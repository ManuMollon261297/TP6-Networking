#pragma once

#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define PORT_S 12345
#define YO	1
#define ESCUCHO 2

class Server
{
public:
	Server(int port);
	~Server();

	void listening();
	bool noerrror();
	bool itsMe(const char * mi_ip);
	bool lastOne();

	void getSequence();
	char * getNext();
	char * getMsg();
	bool getQuit();
	char getAnim();
	int getipsCount();
	void closeSocket();

	void setAnim(char anim);
	void setTurno(int turno);
	void setQuit(bool stat);

	bool setBuf(int pos, char value);
	bool setSeq(int pos, char value);
	char getBuf(int pos);
	char getSeq(int pos);

private:
	bool quit_status;
	bool error_status;

	int turno;
	int ipsCount;

	char animation;

	char ipNext[16];
	char buf[512];
	char sequence[255];

	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;
};


void getUserSequence(Server& S);

/*

void server::writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes) {
	std::cout << std::endl << "Write Callback called" << std::endl;
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
