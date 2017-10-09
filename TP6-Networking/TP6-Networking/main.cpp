#include <iostream>
#include "Animation.h"
#include "Output.h"
#include "Client.h"
#include "Server.h"

int main(int argc, char* argv[]) // Param 1 (mandatorio) = IP propia
{								 // Param 2 (opcional) = Inicial
	
	Server S(PORT_S);
	do{
		//revisar argv a ver si es el inicial o no, modificar S.turno segun esto
		// inicializar allegro
		char my_ip[16]; //llenar con el param 1 de ip propia
		S.listening();
		S.getSequence(); 
		if(S.noerrror()&&S.itsMe(my_ip))
		{
			viewer V(1000, 900);
			V.RunAnimation(S.getAnim());
			if(S.lastOne())
			{
				getUserSequence(S);
			}
		}
		Client C(S.getNext());
		C.startConnection(S.getNext());
		C.sendSeq(S.getMsg());
	} while (!S.getQuit());
	return 0;
}
