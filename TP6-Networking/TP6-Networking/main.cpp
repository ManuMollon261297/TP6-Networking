#include <iostream>
#include "Animation.h"
#include "Client.h"
#include "Server.h"

int main(int argc, char* argv[]) // Param 1 (mandatorio) = IP propia
{								 // Param 2 (opcional) = Imagen Inicial
	
	Server S(PORT);
	do{
		S.listening();
		S.getSequence();
		if(S.noerrror()&&S.itsMe())
		{
			//animation a(S.getAnim());
			//a.show();
			if(S.lastOne())
			{
				getUserSequence(S);

			}
		}
		Client C(S.getNext(),PORT);
		C.sendSeq(S.getMsg());
	} while (!S.getQuit());

	return 0;
}