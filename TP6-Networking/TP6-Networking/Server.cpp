#include "Server.h"


Server::Server(int port) {
	IO_handler = new boost::asio::io_service();
	socket_forServer = new boost::asio::ip::tcp::socket(*IO_handler);
	server_acceptor = new boost::asio::ip::tcp::acceptor(*IO_handler,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT_S));
	std::cout << std::endl << "Ready, Port: " << PORT_S << " created" << std::endl;
	error_status = false;
	quit_status = false;
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
	switch (turno)
	{
		case YO:
		{
			//nothing
		}break;
		case ESCUCHO:
		{
			cout << "Waiting message from client..." << std::endl;
			server_acceptor->accept(*socket_forServer);
			socket_forServer->non_blocking(true);
			size_t len = 0;
			boost::system::error_code error;
			do
			{
				len = socket_forServer->read_some(boost::asio::buffer(buf), error);

			} while (error.value() == WSAEWOULDBLOCK);
			std::cout << std::endl << "Client says: " << buf[0] << *(buf+1) << std::endl;
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

	char ipNew[16];
	ifstream ipData("direcciones.txt");
	int count = buf[1];
	int i = 0;
	while (buf[i + 2] != count)
	{
		i++;
	}
	for (int j = 0; j < i; j++) {		//Ignoro las lineas hasta llegar a la proxima ip
		ipData.ignore(16, '\n');
	}
	ipData.getline(ipNew, 16);
	return !(strcmp(mi_ip, ipNew));
}

void Server::getSequence() //agregar chequeo de error de repetir secuencia
{
	switch (turno)
	{
		case YO:
		{
			ifstream ipData("direcciones.txt");
			char ipNew[16];
			char ip_number = 1;
			do {
				ipData.ignore(16, '\n');
				ip_number++;
			} while (!(ipData.eofbit));
			if (ip_number > 255)
			{
				error_status = true;
			}
			else
			{
				ipsCount = ip_number;
			}
			Server& S = (*this);
			getUserSequence(S);
			setTurno(ESCUCHO);
		}break;
		case ESCUCHO:
		{
			ifstream ipData("direcciones.txt");
			char ipNew[16];
			char ip_number = 1;
			do {
				ipData.ignore(16, '\n');
				ip_number++;
			} while (!(ipData.eofbit));
			if (ip_number > 255)
			{
				error_status = true;
			}
			else
			{
				ipsCount = ip_number;
				for (int i = 0;i<ip_number;i++ )
				{
					if (buf[i + 2] > 255)
					{
						error_status = true;
					}
					sequence[i] = buf[i + 2];
				}
			}
		}break;
	}
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
	if ((buf[1]-1) == counter)
	{
		return true;
	}
	else
	{
		return false;
	}

}

char * Server::getNext()
{
	ifstream ipData("direcciones.txt");
	int count = buf[1]+1;
	int i = 0;
	while (buf[i + 2] != count)
	{
		i++;
	}
	for (int j = 0; j < i; j++) {		//Ignoro las lineas hasta llegar a la proxima ip
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

void Server::setQuit(bool stat)
{
	quit_status = stat;
}

bool Server::setBuf(int pos, char value)
{
	if((pos >= 513) || (pos < 0))
	{
		return false;
	}
	else
	{
		buf[pos] = value;
		return true;
	}
}

bool Server::setSeq(int pos, char value)
{
	if ((pos >= 256) || (pos < 0))
	{
		return false;
	}
	else
	{
		sequence[pos] = value;
		return true;
	}
}

char Server::getBuf(int pos)
{
	if ((pos >= 513) || (pos < 0))
	{
		return -1;
	}
	else
	{
		return buf[pos];
	}
}

char Server::getSeq(int pos)
{
	if ((pos >= 255) || (pos < 0))
	{
		return -1;
	}
	else
	{
		return sequence[pos];
	}
}

char Server::getAnim()
{
	return animation;
}

int Server::getipsCount()
{
	return ipsCount;
}

void Server::closeSocket()
{
	socket_forServer->close();
}

void Server::setAnim(char anim)
{
	animation = anim;
}

void getUserSequence(Server& S) //chequear errores de sequence
{
	char anim;
	int seq;
	S.setBuf(1, 1);
	std::cout << "Choose next animation: (A-F)" << std::endl;
	do
	{
		std::cin >> anim;
		if (anim == 'Q')
		{
			S.setQuit(true);
			cout << "Exiting Program..." << endl;
		}
		else if ((anim < 'A') || (anim > 'F'))
		{
			std::cout << "Invalid animation" << std::endl;
		}
	} while (((anim < 'A') || (anim > 'F'))&&(anim != 'Q'));
	S.setAnim(anim);
	S.setBuf(0, S.getAnim());
	if (S.getQuit() == false) 
	{
		std::cout << "Choose next sequence:" << std::endl;
		for (int i=0;i< S.getipsCount() ;i++)
		{
			do
			{
				std::cin >> seq;
				if ((seq < 0) || (seq > S.getipsCount()))
				{
					std::cout << "Invalid sequence number" << std::endl;
				}
				else
				{
					S.setBuf(2 + i, seq);
				}
			} while ((seq < 0) || (seq > S.getipsCount()));
		}
	}
}
