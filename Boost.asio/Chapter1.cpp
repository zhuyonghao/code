
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
}


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


#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Assume that the client application has already
	// obtained the DNS name and protocol port number and
	// represented them as strings.
	std::string host = "baidu.com";
	std::string port_num = "3333";

	// Step 2.
	asio::io_service ios;

	// Step 3. Creating a query
	asio::ip::tcp::resolver::query resolver_query(host,
		port_num, asio::ip::tcp::resolver::query::numeric_service);

	// Step 4. Creating a resolver
	asio::ip::tcp::resolver resolver(ios);

	// Used to store information about error that happens
	//  during the resolution process

	boost::system::error_code ec;

	// Step 5.
	asio::ip::tcp::resolver::iterator it =
		resolver.resolve(resolver_query, ec);

	// Handing error if any
	if (ec.value() != 0)
	{
		//Failed to resolve DNS name. breaking execution.
		std::cout << "Failed to resolve the DNS name."
			<< "Error code = " << ec.value()
			<< ". Message = " << ec.message();
		return ec.value();
	}
	return 0;
}


// resolve the DNS name   UDP
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Assume that the client application has already
	// obtained the DNS name and protocol port number and
	// represented them as strings.
	std::string host = "baidu.com";
	std::string port_num = "3333";

	// Step 2.
	asio::io_service ios;

	// Step 3. Creating a query
	asio::ip::udp::resolver::query resolver_query(host,
		port_num, asio::ip::udp::resolver::query::numeric_service);

	// Step 4. Creating a resolver.
	asio::ip::udp::resolver resolver(ios);

	// Used to store information about error that happens
	// during the resolution process.
	boost::system::error_code ec;

	// Step 5.
	asio::ip::udp::resolver::iterator it =
		resolver.resolve(resolver_query, ec);

	if (ec.value() != 0)
	{
		// Failed to resolve the DNS name. Breaking execution.
		std::cout << "Failed to reslove a DNS name."
			<< "Error code = " << ec.value()
			<< ".Message = " << ec.message();

		return ec.value();
	}

	asio::ip::udp::resolver::iterator it_end;

	for (; it != it_end; ++it)
		// Here we can access the endpoint like this.
		asio::ip::udp::endpoint ep = it->endpoint();

	return 0;
}


// Binding a socket to an endpoint
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Here we assume that the server application has
	// already obtained the protocol port number.
	unsigned short port_num = 3333;

	// Step 2. Creating an endpoint
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
		port_num);

	// Used by acceptor class constructor
	asio::io_service ios;

	// Step 3. Creating and opening an acceptor socket.
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;

	// Step 4. Bing the acceptor socket.
	acceptor.bind(ep, ec);

	// Handing errors if any.
	if (ec.value() != 0)
	{
		// Failed to bind the acceptor socket. Breaking
		// execution.
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();

		return ec.value();
	}

	return 0;
}



// UDP bind a socket
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Here we assume that the server application has
	// already obtained the protocol number.
	unsigned short port_num = 3333;

	// Step 2. Creating an endpoint.
	asio::ip::udp::endpoint ep(asio::ip::address_v4::any(),
		port_num);

	// Used by socket class constructor.
	asio::io_service ios;

	// Step 3. Creating and opening a socket.
	asio::ip::udp::socket sock(ios, ep.protocol());

	boost::system::error_code ec;

	// Step 4. Binding the socket to an endpoint.
	sock.bind(ep, ec);

	// Handing errors if any.
	if (ec.value() != 0)
	{
		// Failed to bind the acceptor socket. Breaking
		// execution.
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();

		return ec.value();
	}

	return 0;
}


#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Assume that the server application has already
	// obtained the IP address and protocol port number of the
	// targer server
	std::string raw_ip_address = "192.168.0.1";

	unsigned short port_num = 3333;

	try
	{
		// Step 2. Creating an endpoint designating
		// a target server application
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		// Step 3. Creating and opening a socket.
		asio::ip::tcp::socket sock(ios, ep.protocol());

		// Step 4. Connecting a socket.
		sock.connect(ep);

		// At this point socket 'sock' is connected to
		// the server application and can be used
		// to send data to or receive data from it
	}
	// Overload of asio::op::address::from_string() and
	// asio::ip::tcp::socket::connect() used here throw
	// exception in case of error condition

	catch (system::system_error &e)
	{
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}


// the socket's connect() method will bind the socket to the endpoint consisting
//of an IP address and a protocol port number chosen by the operating system



// DNS code
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// Step 1. Assume that the client application has already
	// obtained the DNS name and protocol port number and
	// represent them as strings
	std::string host = "baidu.com";
	std::string port_num = "3333";

	// Used by a resolver and a socket.
	asio::io_service ios;

	// Creating a resolver's query
	asio::ip::tcp::resolver::query resolver_query(host, port_num,
		asio::ip::tcp::resolver::query::numeric_service);

	// Creaing a resolver.
	asio::ip::tcp::resolver resolver(ios);

	try
	{
		// Step 2. Resolving a DNS name.
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);

		// Step 3. Creating a socket.
		asio::ip::tcp::socket sock(ios);

		// Step 4. asio::connect() method iterator over
		// each endpoint until successfully connects to one
		// of them. It will throw an exception if it fails
		// to connect to all the endpoints or if other
		// error occurs.
		asio::connect(sock, it);

		// At this point socket 'sock' is connected to
		// the server application and can be used to
		// send data to or receive data from it.
	}
	// Overload of asio::ip::tcp::resolver::resolve and
	// asio::connect() used here throw
	// exceptions in case of error condition.
	catch (system::system_error &e)
	{
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}
*/

// Accepting connections
#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// The size of the queue containing the pending connection
	// requests.
	const int BACKLOG_SIZE = 30;

	// Step 1. Here we assume that the server application has
	// already obtained the protocol port number.
	unsigned short port_num = 3333;

	// Step 2. Creating a server endpoint.
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
							   port_num);

	asio::io_service ios;

	try
	{
		// Step 3. Instantiating and opening an acceptor socket.
		asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

		// Step 4. Binding the acceptor socket to the
		// server endpoint.
		acceptor.bind(ep);

		// Step 5. Starting to listen for incoming connection
		// requests.
		acceptor.listen(BACKLOG_SIZE);

		// Step 6. Creating an active socket.
		asio::ip::tcp::socket sock(ios);

		// Step 7. Processing the next connection request and
		// connecting the active socket to the client.
		acceptor.accept(sock);

		// At this point 'sock' socket is connected to
		// the client application and can be used to send data to
		// or recive data from it.
	}

	catch (system::system_error &e)
	{
		std::cout << "Error occured! Error code = " << e.code()
				  << ". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}
