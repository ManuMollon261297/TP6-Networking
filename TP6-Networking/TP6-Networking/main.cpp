#include <iostream>
#include "Animation.h"
#include "Client.h"
#include "Server.h"

int main(int argc, char* argv[]) // Param 1 (mandatorio) = IP propia
{								 // Param 2 (opcional) = Inicial
	
	Server S(PORT);
	do{
		//revisar argv a ver si es el inicial o no, modificar S.turno segun esto
		char * my_ip; //llenar con el param 1 de ip propia
		S.listening();
		S.getSequence();
		if(S.noerrror()&&S.itsMe(my_ip))
		{
			Animation a(S.getAnim());
			//a.show();
			if(S.lastOne())
			{
				getUserSequence(S);

			}
		}
		//Client C(S.getNext(),PORT);
		//C.startConnection(S.getNext());
		//C.sendSeq(S.getMsg());
	} while (!S.getQuit());

	return 0;
}
