#pragma once

#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define PORT 50013

class Server
{
public:
	Server(int port);
	~Server();
	void listening();
	void getSequence();
	bool noerrror();
	bool itsMe(const char * mi_ip, char buff[]);
	bool lastOne();
	void getNext();
	void getMsg();
	bool getQuit();
private:
	bool quit;
	friend char getUserSequence(Server& S);
	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;
};


void Server::listening() {
	server_acceptor->accept(*socket_forServer);
	socket_forServer->non_blocking(true);
}


Server::Server(int port) {
	IO_handler = new boost::asio::io_service();
	socket_forServer = new boost::asio::ip::tcp::socket(*IO_handler);
	server_acceptor = new boost::asio::ip::tcp::acceptor(*IO_handler,
	boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT));
	std::cout << std::endl << "Ready. Port " << PORT << " created" << std::endl;
}

Server::~Server() {
	server_acceptor->close();
	socket_forServer->close();
	delete server_acceptor;
	delete socket_forServer;
	delete IO_handler;
}

bool Server::itsMe(const char * mi_ip, char buff[]) {
	ifstream ipData("IPDATA.txt");
	char ipNew[16];
	for (char i = 0; i < buff[1]; i++) {		//Ignoro las lineas hasta llegar a la ip actual
		ipData.ignore(16, '\n');
	}
	ipData.getline(ipNew, 16);

	return !(strcmp(mi_ip,ipNew));
}

/*
#include <cstdio>
#include <cstring>

class server {
public:
	void startConnection();
	void sendMessage();
	void writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes);
};

void server::writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes) {
	std::cout << std::endl << "Write Callback called" << std::endl;
}

void server::startConnection() {
	server_acceptor->accept(*socket_forServer);
	socket_forServer->non_blocking(true);
}

void server::sendMessage() {
	char buf[512] = "Hello from server.";

	size_t len;
	boost::system::error_code error;

	do
	{
		len = socket_forServer->write_some(boost::asio::buffer(buf, strlen(buf)), error);
	} while ((error.value() == WSAEWOULDBLOCK));
	if (error)
		std::cout << "Error while trying to connect to server " << error.message() << std::endl;
}
void TCPserver()
{
	server conquering;
	std::cout << std::endl << "Start Listening on port " << HELLO_PORT << std::endl;
	conquering.startConnection();
	std::cout << "Somebody connected to port " << HELLO_PORT << std::endl;
	std::cout << "Press Enter to Send Message  " << std::endl;
	getchar();
	conquering.sendMessage();
	Sleep(50); // Le damos 50ms para que llegue el mensaje antes de cerrar el socket.
}
int main(int argc, char* argv[])
{
	TCPserver();
}
*/
