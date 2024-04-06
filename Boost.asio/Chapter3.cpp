/*
// a synchronous TCP client
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

class SyncTCPClient
{
public:
    SyncTCPClient(const std::string& raw_ip_address,
        unsigned short port_num) :
        m_ep(asio::ip::address::from_string(raw_ip_address),
        port_num),
        m_sock(m_ios) {
        m_sock.open(m_ep.protocol());
    }

    void connect()
    {
        m_sock.open(m_ep.protocol());
    }

    void close()
    {
        m_sock.shutdown(
            boost::asio::ip::tcp::socket::shutdown_both);
        m_sock.close();
    }

    std::string emulateLongComputationOp(
        unsigned int duration_sec) {
        std::string request = "EMULATE_LONG_COMP_OP "
            + std::to_string(duration_sec)
            + "\n";

        sendRequest(request);
        return receiveResponse();
    }

private:
    void sendRequest(const std::string& request)
    {
        asio::write(m_sock, asio::buffer(request));
    }

    std::string receiveResponse()
    {
        asio::streambuf buf;
        asio::read_until(m_sock, buf, '\n');
        std::istream input(&buf);

        std::string response;
        std::getline(input, response);

        return response;
    }

private:
    asio::io_service m_ios;

    asio::ip::tcp::endpoint m_ep;
    asio::ip::tcp::socket m_sock;
};

int main()
{
    const std::string raw_ip_address = "127.0.0.1";
    const unsigned short port_num = 3333;

    try
    {
        SyncTCPClient client(raw_ip_address, port_num);

        // Sync connect
        client.connect();

        std::cout << "Sending request to server..." << std::endl;

        std::string response =
            client.emulateLongComputationOp(10);

        std::cout << "Response received: " << response
            << std::endl;

        // Close the connection and free resources.
        client.close();
    }
    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}


// a synchronous UDP client
#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

class SyncUDPClient
{
public:
    SyncUDPClient() :
        m_sock(m_ios)
    {
        m_sock.open(asio::ip::udp::v4());
    }

    std::string emulateLongComputationOp(
        unsigned int duration_sec,
        const std::string& raw_ip_address,
        unsigned short port_num)
    {
        std::string request = "EMULATE_LONG_COMP_OP "
            + std::to_string(duration_sec)
            + "\n";

        asio::ip::udp::endpoint ep(
            asio::ip::address::from_string(raw_ip_address),
            port_num);

        sendRequest(ep, request);
        return receiveResponse(ep);
    }

private:
    void sendRequest(const asio::ip::udp::endpoint& ep,
        const std::string& request)
    {
        m_sock.send_to(asio::buffer(request), ep);
    }

    std::string receiveResponse(asio::ip::udp::endpoint& ep)
    {
        char response[6];
        std::size_t bytes_received =
            m_sock.receive_from(asio::buffer(response), ep);

        m_sock.shutdown(asio::ip::udp::socket::shutdown_both);
        return std::string(response, bytes_received);
    }

private:
    asio::io_service m_ios;

    asio::ip::udp::socket m_sock;
};

int main()
{
    const std::string server1_raw_ip_address = "127.0.0.1";
    const unsigned short server1_port_num = 3333;

    const std::string server2_raw_ip_address = "192.168.1.10";
    const unsigned short server2_port_num = 3334;

    try
    {
        SyncUDPClient client;

        std::cout << "Sending request to the server #1 ... "
            << std::endl;

        std::string response =
            client.emulateLongComputationOp(10,
                server1_raw_ip_address, server1_port_num);

        std::cout << "Response from the server #1 received: "
            << response << std::endl;

        std::cout << "Sending request to the server #2 ... "
            << std::endl;

        response =
            client.emulateLongComputationOp(10,
                server2_raw_ip_address, server2_port_num);

        std::cout << "Response from the server #2 received: "
            << response << std::endl;
    }
    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}
*/

// implement an asynchronous TCP client
#include <boost/predef.h> // Tools to identify the OS.
// We need this to enable cancelling of I/O operations on
// Windows XP, Windows Server 2003 and earlier.
// Refer to "http://www.boost.org/doc/libs/1_58_0/
// doc/html/boost_asio/reference/basic_stream_socket/
// cancel/overload1.html" for details.
#ifdef BOOST_OS_WINDOWS
#define _WIN32_WINNT 0x0501
#if _WIN32_WINNT <= 0x0502 // Windows Server 2003 or earlier.
#define BOOST_ASIO_DISABLE_IOCP
#define BOOST_ASIO_ENABLE_CANCELIO
#endif
#endif

#include <boost/asio.hpp>
#include <thread>
#include <mutex>
#include <memory>
#include <iostream>
#include <map>
using namespace boost;

// Function pointer type that points to the callback
// function which is called when a request is complete.
typedef void (*Callback)(unsigned int request_id,
                         const std::string &response,
                         const system::error_code &ec);
struct Session
{
    Session(asio::io_service &ios,
            const std::string &raw_ip_address,
            unsigned short port_num,
            const std::string &request,
            unsigned int id,
            Callback callback) : m_sock(ios),
                                 m_ep(asio::ip::address::from_string(raw_ip_address),
                                      port_num),
                                 m_request(request),
                                 m_id(id),
                                 m_callback(callback),
                                 m_was_cancelled(false) {}
    asio::ip::tcp::socket m_sock; // Socket used for communication
    asio::ip::tcp::endpoint m_ep; // Remote endpoint.
    std::string m_request;        // Request string.
    // streambuf where the response will be stored.
    asio::streambuf m_response_buf;
    std::string m_response; // Response represented as a string.
    // Contains the description of an error if one occurs during
    // the request life cycle.
    system::error_code m_ec;
    unsigned int m_id; // Unique ID assigned to the request.
    // Pointer to the function to be called when the request
    // completes.
    Callback m_callback;
    bool m_was_cancelled;
    std::mutex m_cancel_guard;
};

class AsyncTCPClient : public boost::noncopyable
{
    class AsyncTCPClient : public boost::noncopyable
    {
    public:
        AsyncTCPClient()
        {
            m_work.reset(new boost::asio::io_service::work(m_ios));
            m_thread.reset(new std::thread([this]()
                                           { m_ios.run(); }));
        }
        void emulateLongComputationOp(
            unsigned int duration_sec,
            const std::string &raw_ip_address,
            unsigned short port_num,
            Callback callback,
            unsigned int request_id)
        {
            // Preparing the request string.
            std::string request = "EMULATE_LONG_CALC_OP " + std::to_string(duration_sec) + "\n";
            std::shared_ptr<Session> session =
                std::shared_ptr<Session>(new Session(m_ios,
                                                     raw_ip_address,
                                                     port_num,
                                                     request,
                                                     request_id,
                                                     callback));
            session->m_sock.open(session->m_ep.protocol());
            // Add new session to the list of active sessions so
            // that we can access it if the user decides to cancel
            // the corresponding request before it completes.
            // Because active sessions list can be accessed from
            // multiple threads, we guard it with a mutex to avoid
            // data corruption.
            std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);
            m_active_sessions[request_id] = session;
            lock.unlock();
            session->m_sock.async_connect(session->m_ep,
                                          [this, session](const system::error_code &ec)
                                          {
                    if (ec.value() != 0) {
                        session->m_ec = ec;
                        onRequestComplete(session);
                        return;
                    }
                    std::unique_lock<std::mutex>
                        cancel_lock(session->m_cancel_guard);
                    if (session->m_was_cancelled) {
                        onRequestComplete(session);
                        return;
                    }
                    asio::async_write(session->m_sock,
                        asio::buffer(session->m_request),
                        [this, session](const boost::system::error_code& ec,
                            std::size_t bytes_transferred)
                        {
                            if (ec.value() != 0) {
                                session->m_ec = ec;
                                onRequestComplete(session);
                                return;
                            }
                            std::unique_lock<std::mutex>
                                cancel_lock(session->m_cancel_guard);
                            if (session->m_was_cancelled) {
                                onRequestComplete(session);
                                return;
                            }
                            asio::async_read_until(session->m_sock,
                                session->m_response_buf,
                                '\n',
                                [this, session](const boost::system::error_code& ec,
                                    std::size_t bytes_transferred)
                                {
                                    if (ec.value() != 0) {
                                        session->m_ec = ec;
                                    }
                                    else {
                                        std::istream strm(&session->m_response_buf);
                                        std::getline(strm, session->m_response);
                                    }
                                    onRequestComplete(session);
                                }); }); });
        };
        // Cancels the request.
        void cancelRequest(unsigned int request_id)
        {
            std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);
            auto it = m_active_sessions.find(request_id);
            if (it != m_active_sessions.end())
            {
                std::unique_lock<std::mutex>
                    cancel_lock(it->second->m_cancel_guard);
                it->second->m_was_cancelled = true;
                it->second->m_sock.cancel();
            }
        }
        void close()
        {
            // Destroy work object. This allows the I/O thread to
            // exits the event loop when there are no more pending
            // asynchronous operations.
            m_work.reset(NULL);
            // Wait for the I/O thread to exit.
            m_thread->join();
        }

    private:
        void onRequestComplete(std::shared_ptr<Session> session)
        {
            // Shutting down the connection. This method may
            // fail in case socket is not connected. We don’t care
            // about the error code if this function fails.
            boost::system::error_code ignored_ec;
            session->m_sock.shutdown(
                asio::ip::tcp::socket::shutdown_both,
                ignored_ec);
            // Remove session form the map of active sessions.
            std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);
            auto it = m_active_sessions.find(session->m_id);
            if (it != m_active_sessions.end())
                m_active_sessions.erase(it);
            lock.unlock();
            boost::system::error_code ec;
            if (session->m_ec.value() == 0 && session->m_was_cancelled)
                ec = asio::error::operation_aborted;
            else
                ec = session->m_ec;
            // Call the callback provided by the user.
            session->m_callback(session->m_id,
                                session->m_response, ec);
        };

    private:
        asio::io_service m_ios;
        std::map<int, std::shared_ptr<Session>> m_active_sessions;
        std::mutex m_active_sessions_guard;
        std::unique_ptr<boost::asio::io_service::work> m_work;
        std::unique_ptr<std::thread> m_thread;
    };
} void handler(unsigned int request_id,
               const std::string &response,
               const system::error_code &ec)
{
    if (ec.value() == 0)
    {
        std::cout << "Request #" << request_id
                  << " has completed. Response: "
                  << response << std::endl;
    }
    else if (ec == asio::error::operation_aborted)
    {
        std::cout << "Request #" << request_id
                  << " has been cancelled by the user."
                  << std::endl;
    }
    else
    {
        std::cout << "Request #" << request_id
                  << " failed! Error code = " << ec.value()
                  << ". Error message = " << ec.message()
                  << std::endl;
    }
    return;
}

int main()
{
    try
    {
        AsyncTCPClient client;
        // Here we emulate the user's behavior.
        // User initiates a request with id 1.
        client.emulateLongComputationOp(10, "127.0.0.1", 3333,
                                        handler, 1);
        // Then does nothing for 5 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(5));
        // Then initiates another request with id 2.
        client.emulateLongComputationOp(11, "127.0.0.1", 3334,
                                        handler, 2);
        // Then decides to cancel the request with id 1.
        client.cancelRequest(1);
        // Does nothing for another 6 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(6));
        // Initiates one more request assigning ID3 to it.
        client.emulateLongComputationOp(12, "127.0.0.1", 3335,
                                        handler, 3);
        // Does nothing for another 15 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(15));
        // Decides to exit the application.
        client.close();
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}