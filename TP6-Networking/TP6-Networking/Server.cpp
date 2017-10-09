#include "Server.h"


Server::Server(int port) {
	IO_handler = new boost::asio::io_service();
	socket_forServer = new boost::asio::ip::tcp::socket(*IO_handler);
	server_acceptor = new boost::asio::ip::tcp::acceptor(*IO_handler,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT_S));
	std::cout << std::endl << "Ready, Port: " << PORT_S << " created" << std::endl;
	error_status = false;
	quit_status = false;
	sequence = '0';
	animation = '0';
}

Server::~Server() {
	server_acceptor->close();
	socket_forServer->close();
	delete server_acceptor;
	delete socket_forServer;
	delete IO_handler;
}

void Server::listening() {
	server_acceptor->accept(*socket_forServer);
	socket_forServer->non_blocking(true);
	switch (turno)
	{
		case YO:
		{
		}break;
		case ESCUCHO:
		{
			size_t len = 0;
			boost::system::error_code error;
			cout << "Recibiendo mensaje del Client" << std::endl;
			do
			{
				len = socket_forServer->read_some(boost::asio::buffer(buf), error);

			} while (error.value() == WSAEWOULDBLOCK);
			std::cout << std::endl << "Client dice: " << buf << std::endl;
			if ((buf[0] >= 'A') && (buf[0] <= 'F'))
			{
				animation = buf[0];
			}
			else
			{
				error_status = true;
			}
		}break;
	}
}

bool Server::itsMe(const char * mi_ip) {
	ifstream ipData("direcciones.txt");
	char ipNew[16];
	for (char i = 0; i < buf[1]; i++) {		//Ignoro las lineas hasta llegar a la ip actual
		ipData.ignore(16, '\n');
	}
	ipData.getline(ipNew, 16);

	return !(strcmp(mi_ip, ipNew));
}

char Server::getSequence() //TERMINAR
{
	return 0;
}

bool Server::noerrror()
{
	return (!error_status);
}

bool Server::lastOne()
{
	ifstream ipData("direcciones.txt");
	char ipNew[16];
	char counter = 0;
	do{	
		ipData.ignore(16, '\n');
		counter++;
	} while (!(ipData.eofbit));
	if (buf[1] == counter)
	{
		return true;
	}
	else
	{
		return false;
	}

}

char * Server::getNext() //arreglar con sequence 
{
	ifstream ipData("direcciones.txt");
	for (char i = 0; i < buf[1]+1; i++) {		//Ignoro las lineas hasta llegar a la proxima ip
		ipData.ignore(16, '\n');
	}
	ipData.getline(ipNext, 16);
	return ipNext;
}

char * Server::getMsg()
{
	return buf;
}

bool Server::getQuit()
{
	return quit_status;
}

void Server::setTurno(int turno_)
{
	turno = turno_;
}

char Server::getAnim()
{
	return animation;
}

void Server::setAnim(char anim)
{
	animation = anim;
}

void getUserSequence(Server& S) //TERMINAR PARTE DE SEQUENCE
{
	char anim;
	std::cout << "Choose next animation" << std::endl;
	do
	{
		std::cin >> anim;
		if ((anim < 'A') || (anim > 'F'))
		{
			std::cout << "Invalid animation" << std::endl;
		}
	} while ((anim < 'A') || (anim > 'F'));
	S.setAnim(anim);
}
