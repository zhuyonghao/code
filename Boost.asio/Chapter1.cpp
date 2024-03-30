
/*
// Creating an endpoint in the client to designate the server

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. assume that the client application has 
	// obtained the IP-address and the protocal port number
	std::string raw_ip_address = "192.168.1.0";
	unsigned short port_num = 3333;


	// used to store information about error that happens
	// While parsing the raw IP-address
	boost::system::error_code ec;


	// Step 2. Using IP protocol version independent address
	// representation
	asio::ip::address ip_address =
		asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0)
	{
		// Provided IP address is invalid. Breaking execution.  
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	// Step 3.
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// Step 4. The endpoint is ready and can be used to specify a
	// particular server in the network the client wants to
	// communicate with.

	return 0;


}



// Create the server endpoint

#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
	// Step 1. Here we assume that the server application has
	// already obtained the protocol  port number.
	unsigned short port_num = 3333;

	// Step 2. Create special object of asio::ip::address class
	// that specifies all IP-addresses available on the host. Note
	// that here we consume that server works over IPv6 protocal.
	asio::ip::address ip_address = asio::ip::address_v6::any();

	// Step 3.
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// Step 4. The endpoint is created and can be used to 
	// specifies the IP addresses and a port number on which
	// the server application wants to listen for incoming
	// connections.

	return 0;
}

// Create an active socket
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. An instance of 'io_service' class is required by
	// socket constructor
	asio::io_service ios;

	// Step 2. Creating an object of 'tcp' class representing
	// a TCP protocol with IPv4 as underlying protocol.
	asio::ip::tcp protocol = asio::ip::tcp::v4();

	// Step 3. Instantiating an active TCP socket object.
	asio::ip::tcp::socket sock(ios);

	// Used to store infomation about error that happens
	// While opening the socket
	boost::system::error_code ec;

	// Step 4. Opening the socket.
	sock.open(protocol, ec);

	if (ec.value() != 0)
	{
	// Failed to open the socket.
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	return 0;
}


// How to create an active UDP socket
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. An instance of io_service class is required by
	// socket constructor
	asio::io_service ios;

	/// Step 2. Creating an object of udp class representing
	// a UDP protocol with IPv6 as underLying protocol
	asio::ip::udp protocol = asio::ip::udp::v6();

	// Step 3. Instantiating an active UDP object.
	asio::ip::udp::socket sock(ios);

	// Used to store information about error that happens
	// While opening the socket
	boost::system::error_code ec;

	// Step 4. opening the socket.
	sock.open(protocol, ec);

	if (ec.value() != 0)
	{
		// Failed to open the socket.
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	return 0;
}*/


// Create a passive socket
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. An instantiate of 'io_service' class is required by
	// socket constructor.
	asio::io_service ios;

	// Step 2. Creating an object of 'tcp' class representing
	// a TCP protocol with Ipv6 as underlying protocol.
	asio::ip::tcp protocol = asio::ip::tcp::v6();

	// Step 3. Instantiating an acceptor socket object.
	// allocate the actual socket object of the underlying operating system
	asio::ip::tcp::acceptor acceptor(ios);

	// Used to store information about error that happens
	// While opening the acceptor socket.
	boost::system::error_code ec;

	// Step 4. Opening the acceptor socket.
	acceptor.open(protocol, ec);

	if (ec.value() != 0)
	{
		// Failed to open the socket.
		std::cout
			<< "Failed to open the acceptor socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	return 0;
}