/*
// Using fixed length I/O buffer
// Prepare a buffer for an output operation
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
    const std::string buf = "Hello"; // 'buf' is raw buffer.

    // Step 3. Creating buffer representation that satisfies
    // ConstBufferSequency concept requirements.
    asio::const_buffers_1 output_buf = asio::buffer(buf);

    // Step 4. 'output_buf' is the representation of the
    // buffer 'buf' that can be used in Boost.Asio output
    // operations.

    return 0;
}


// Prepare a buffer for an input operation
#include <iostream>
#include <boost/asio.hpp>
#include <memory>
using namespace boost;

int main()
{
    // We expect to receive a block of data no more than 20 bytes
    // long
    const size_t BUF_SIZE_BYTES = 20;

    // Step 1. Allocating the buffer.
    std::unique_ptr<char[]> buf(new char[BUF_SIZE_BYTES]);

    // Step 2. Creating buffer representation that satisfies
    // MutableBufferSequence concept requirements.
    asio::mutable_buffers_1 input_buf =
        asio::buffer(static_cast<void*>(buf.get()),
            BUF_SIZE_BYTES);

    // Step 3. 'input_buf' is the representation of the buffer
    // 'buf' that can be used in Boost.Asio input operations.
    return 0;
}


// Using extensible stream-oriented I/O buffers
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
    asio::streambuf buf;

    std::ostream output(&buf);

    // Writing the message to the stream-based buffer
    output << "Message1\nMessage2";

    // Now we want to read all data from a streambuf
    // Until '\n' delimiter.
    // Instantiate an input stream which use
    // our stream buffer.
    std::istream input(&buf);

    // We'll read data into this string.
    std::string message1;
    std::getline(input, message1);

    // Now message1 string contains 'Message1'.

    return 0;
}


#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

void writeToSocket(asio::ip::tcp::socket& sock)
{
    // Step 2. Allocating and filling the buffer.
    std::string buf = "Hello";

    std::size_t total_bytes_written = 0;

    // Step 3. Run the loop until all data is written
    // to the socket.
    while (total_bytes_written != buf.length())
    {
        total_bytes_written += sock.write_some(
            asio::buffer(buf.c_str() +
                total_bytes_written,
                buf.length() - total_bytes_written));
    }
}

int main()
{
    std::string raw_ip_address = "192.168.1.0";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        // Step 1. Allocating and opening the socket.
        asio::ip::tcp::socket sock(ios, ep.protocol());

        sock.connect(ep);

        writeToSocket(sock);
    }
    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}


// Reading from a tcp socket synchronously
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

std::string readFromSocket(asio::ip::tcp::socket& sock)
{
    const unsigned char MESSAGE_SIZE = 7;
    char buf[MESSAGE_SIZE];
    std::size_t total_bytes_read = 0;

    while (total_bytes_read != MESSAGE_SIZE)
    {
        total_bytes_read += sock.read_some(
            asio::buffer(buf + total_bytes_read,
                MESSAGE_SIZE - total_bytes_read)
        );
    }

    return std::string(buf, total_bytes_read);
}

int main()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        asio::ip::tcp::socket sock(ios, ep.protocol());

        sock.connect(ep);

        readFromSocket(sock);
    }
    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();
        return e.code().value();
    }
}


#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

// keeps objects we need in a callback to
// identity whether all data has been written
// to the socket and to initiate nect asnyc
// writing operation if needed

struct Session
{
    std::shared_ptr<asio::ip::tcp::socket> sock;
    std::string buf;
    std::size_t total_bytes_written;
};

// Function used as a callback for
// asnychronous writing operation
// Checks if all data from the buffer has
// been written to the socket and initiates
// new asynchronous writing operation if needed.
void callback(const boost::system::error_code& ec,
    std::size_t bytes_transferred,
    std::shared_ptr<Session> s)
{
    if (ec.value() != 0)
    {
        std::cout << "Error occured! Error code = "
            << ec.value()
            << ". Message: " << ec.message();

        return;
    }

    s->total_bytes_written += bytes_transferred;

    if (s->total_bytes_written == s->buf.length())
    {
        return;
    }

    s->sock->async_write_some(
        asio::buffer(
            s->buf.c_str() +
            s->total_bytes_written,
            s->buf.length() -
            s->total_bytes_written),
        std::bind(callback, std::placeholders::_1,
            std::placeholders::_2, s));
}

void writeToSocket(std::shared_ptr<asio::ip::tcp::socket> sock)
{
    std::shared_ptr<Session> s(new Session);

    // Step 4. Allocating and filling the buffer.
    s->buf = std::string("Hello");
    s->total_bytes_written = 0;
    s->sock = sock;

    // Step 5. Initiating asynchronous write operation.
    s->sock->async_write_some(
        asio::buffer(s->buf),
        std::bind(callback,
            std::placeholders::_1,
            std::placeholders::_2,
            s)
    );
}

int main()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        // Step 3. Allocating, opening and connecting a socket.
        std::shared_ptr<asio::ip::tcp::socket> sock(
            new asio::ip::tcp::socket(ios, ep.protocol()));

        sock->connect(ep);

        writeToSocket(sock);

        // Step 6.
        ios.run();
    }

    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
}

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

// Keeps objects we need in a callback to
// identity whether all data has been read
// from the socket and to initiate next async
// reading operation if needed

struct Session
{
    std::shared_ptr<asio::ip::tcp::socket> sock;
    std::unique_ptr<char[]> buf;
    std::size_t total_bytes_read;
    unsigned int buf_size;
};

// Function used as a callback for
// asynchronous reading operation.
// Checks if all data has been read;
// from the socket and initiates
// new reading operation if needed.
void callback(const boost::system::error_code& ec,
    std::size_t bytes_transferred,
    std::shared_ptr<Session> s)
{
    if (ec.value() != 0)
    {
        std::cout << "Error occured! Error code = "
            << ec.value()
            << ". Message: " << ec.message();

        return;
    }

    s->total_bytes_read += bytes_transferred;

    if (s->total_bytes_read == s->buf_size)
    {
        return;
    }

    s->sock->async_read_some(
        asio::buffer(
            s->buf.get() +
            s->total_bytes_read,
            s->buf_size -
            s->total_bytes_read),
        std::bind(callback, std::placeholders::_1,
            std::placeholders::_2, s));
}

void readFromSocket(std::shared_ptr<asio::ip::tcp::socket> sock)
{
    std::shared_ptr<Session> s(new Session);

    // Step 4 Allocating the buffer.
    const unsigned int  MESSAGE_SIZE = 7;

    s->buf.reset(new char[MESSAGE_SIZE]);
    s->total_bytes_read = 0;
    s->sock = sock;
    s->buf_size = MESSAGE_SIZE;

    // Step 5. Initiating asynchronous reading operation.
    s->sock->async_read_some(
        asio::buffer(s->buf.get(), s->buf_size),
        std::bind(callback,
            std::placeholders::_1,
            std::placeholders::_2,
            s));
}

int main()
{
    std::string raw_ip_address = "127.0.0.1";

    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        // Step 3. Allocating, opening and connecting a socket.
        std::shared_ptr<asio::ip::tcp::socket> sock(
            new asio::ip::tcp::socket(ios, ep.protocol()));

        sock->connect(ep);

        readFromSocket(sock);

        // Step 6.
        ios.run();
    }

    catch (system::system_error &e)
    {
        std::cout << "Error code! Error code = " << e.code()
            << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}


// Canceling asynchronous operations
#include <boost/predef.h>

#ifdef BOOST_OS_WINDOWS
#define _WIN32_WINNT 0x0501

#if _WIN32_WINNT <= 0x0502 // Windows Server 2003 or earlier.
#define BOOST_ASIO_DISABLE_IOCP
#define BOOST_ASIO_ENABLE_CANCELIO
#endif
#endif

#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using namespace boost;

int main()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        std::shared_ptr<asio::ip::tcp::socket> sock(
            new asio::ip::tcp::socket(ios, ep.protocol()));

        sock->async_connect(ep,
            [sock](const boost::system::error_code& ec)
            {
                // if asynchronous operation has been
                // cancelled or an error occured during
                // execution, ec contains corresponding
                // error code.
                if (ec.value() != 0)
                {
                    if (ec == asio::error::operation_aborted)
                    {
                        std::cout << "Operation cancelled!";
                    }
                    else
                    {
                        std::cout << "Error occured!"
                            << " Error code = "
                            << ec.value()
                            << ". Message: "
                            << ec.message();
                    }
                    return;
                }
                // At this point the socket is connected and
                // can be used for communication with
                // remote application.
            }
        );

        // Starting a thread, which will be used
        // to call the callback when asynchronous
        // operation completes.
        std::thread worker_thread([&ios]()
            {
                try
                {
                    ios.run();
                }
                catch (system::system_error& e)
                {
                    std::cout << "Error occured!"
                        << " Error code = " << e.code()
                        << ". Message: " << e.what();
                }
            });

        // Emulating delay
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Cancelling the initiating operation.
        sock->cancel();

        // Waiting for the worker thread to complete.
        worker_thread.join();
    }

    catch (system::system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
            << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}


//shutdown on the client application

#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

void communicate(asio::ip::tcp::socket& sock)
{
    // Allocating and filling the buffer with
    // binary data.
    const char request_buf[] = { 0x48, 0x65, 0x0, 0x6c, 0x6c, 0x6f };

    // Sending the request data.
    asio::write(sock, asio::buffer(request_buf));

    // Shutting down the socket to let the
    // server know that we've sent the whole
    // request.
    sock.shutdown(asio::socket_base::shutdown_send);

    // We use extensible buffer for response
    // because we don't know the size of the
    // response message.
    asio::streambuf response_buf;

    system::error_code ec;
    asio::read(sock, response_buf, ec);

    if (ec == asio::error::eof)
    {
        // Whole response message has been received.
        // Here we can handle it.
    }
    else
    {
        throw system::system_error(ec);
    }
}

int main()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint
            ep(asio::ip::address::from_string(raw_ip_address),
                port_num);

        asio::io_service ios;

        asio::ip::tcp::socket sock(ios, ep.protocol());

        sock.connect(ep);

        communicate(sock);
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

// shutdown on the server application
#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

void processRequest(asio::ip::tcp::socket &sock)
{
    // We use extensible buffer because we don't
    // know the size of the request message.
    asio::streambuf request_buf;

    system::error_code ec;

    // Receiving the request.
    asio::read(sock, request_buf, ec);

    if (ec != asio::error::eof)
        throw system::system_error(ec);

    // Request received. Sending response.
    // Allocating and filling the buffer with
    // binary data.
    const char response_buf[] = {0x48, 0x69, 0x21};

    // Sending the request data.
    asio::write(sock, asio::buffer(response_buf));

    // Shutting down the socket to let the
    // client know that we've sent the whole
    // response.
    sock.shutdown(asio::socket_base::shutdown_send);
}

int main()
{
    unsigned short port_num = 3333;

    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
                                   port_num);
        asio::io_service ios;

        asio::ip::tcp::acceptor acceptor(ios, ep);

        asio::ip::tcp::socket sock(ios);

        acceptor.accept(sock);

        processRequest(sock);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}