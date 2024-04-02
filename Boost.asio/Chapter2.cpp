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
*/

// Reading from a tcp socket synchronously
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

std::string readFromSocket(asio::ip::tcp::socket &sock)
{
    const unsigned char MESSAGE_SIZE = 7;
    char buf[MESSAGE_SIZE];
    std::size_t total_bytes_read = 0;

    while (total_bytes_read != MESSAGE_SIZE)
    {
        total_bytes_read += sock.read_some(
            asio::buffer(buf + total_bytes_read,
                         MESSAGE_SIZE - total_bytes_read));
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
    catch (system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();
        return e.code().value();
    }
}