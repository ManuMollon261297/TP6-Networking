#pragma once

#include <cstdio>
#include <string>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>


#define PORT_C "12345"
#define SERVER_IP "localhost"

using namespace std;

class Client
{
public:
	Client(const char * ip);
	~Client();
	void startConnection(const char* host);
	void sendSeq(char * msg);
private:
	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socket_forClient;
	boost::asio::ip::tcp::resolver* client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
	char NextIp[16];
};


Client::Client(const char * ip) {
	IO_handler = new boost::asio::io_service();
	socket_forClient = new boost::asio::ip::tcp::socket(*IO_handler);
	client_resolver = new boost::asio::ip::tcp::resolver(*IO_handler);
	for (int i = 0; i < 16; i++)
	{
		NextIp[i] = ip[0];
	}

}

Client::~Client() {
	socket_forClient->close();
	delete client_resolver;
	delete socket_forClient;
	delete IO_handler;
}

void Client::startConnection(const char* host) {
	endpoint = client_resolver->resolve(boost::asio::ip::tcp::resolver::query(host, PORT_C);
	//endpoint = client_resolver->resolve(boost::asio::ip::tcp::resolver::query(host,);
	//cout << "Trying to connect to " << host << " on port " << PORT << std::endl;
	boost::asio::connect(*socket_forClient, endpoint);
	socket_forClient->non_blocking(true);
}

/*

class client {
public:
	client();
	void startConnection(const char* host);
	void receiveMessage();
	~client();
};

void client::startConnection(const char* host) {
	endpoint = client_resolver->resolve(
		boost::asio::ip::tcp::resolver::query(host, HELLO_PORT_STR));
	cout << "Trying to connect to " << host << " on port " << HELLO_PORT_STR << std::endl;
	boost::asio::connect(*socket_forClient, endpoint);
	socket_forClient->non_blocking(true);
}

void client::receiveMessage() {
	boost::system::error_code error;
	char buf[512];
	size_t len = 0;
	cout << "Receiving Message" << std::endl;
	boost::timer::cpu_timer t;
	t.start();
	boost::timer::cpu_times pastTime = t.elapsed();
	double elapsedSeconds = 0.0;
	do
	{
		len = socket_forClient->read_some(boost::asio::buffer(buf), error);

		boost::timer::cpu_times currentTime = t.elapsed();

		if ((currentTime.wall - pastTime.wall) > 1e9)
		{
			elapsedSeconds += (currentTime.wall - pastTime.wall) / 1e9;
			pastTime = currentTime;
			cout << "Pasaron " << elapsedSeconds << " segundos." << endl;
		}

		if (!error)
			buf[len] = '\0';

	} while (error.value() == WSAEWOULDBLOCK);

	if (!error)
		std::cout << std::endl << "Server sais: " << buf << std::endl;
	else
		std::cout << "Error while trying to connect to server " << error.message() << std::endl;
}

void asioTcpClient(const char* host)
{
	client conquering;
	conquering.startConnection(host);
	conquering.receiveMessage();

}
#include <Windows.h>
int main(int argc, char* argv[])
{
	asioTcpClient(SERVER_IP);
	std::cout << "Press Enter to exit..." << std::endl;
	getchar();
}
*/
