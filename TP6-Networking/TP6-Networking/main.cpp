#include <iostream>
#include <cstdlib>

#include "Output.h"
#include "Client.h"
#include "Server.h"
#include "ParserFunc.h"
#include "userData.h"

#define ON 1
#define OFF 0

int isanumber(char* value);
int Callback(char *key, char *value, void *userData);
void help(void);
int CheckParameters(userDataType *uData);

int main(int argc, char* argv[]) // Param 1 (mandatorio) = IP propia
{								 // Param 2 (opcional) = Inicial
	if (!al_init())
	{
		exit (-1);
	}
	userDataType uData = { NULL, "255.255.255.255", OFF};
	userDataType Flags = { NULL, "OFF", OFF};
	uData.Flag = &Flags;
	uData.myIP;
	if (parsecmdline(argc, argv, &Callback, &uData) == -1)
	{
		exit(-1);
	}
	//Parseo
	if (CheckParameters(&uData)) 
	{
		exit (-1);
	}
	//Verifica datos compatibles y los printea si no hay error
	Server S(PORT_S);
	if (Flags.inicia)
	{
		S.setTurno(YO);
	}
	else
	{
		S.setTurno(ESCUCHO);
	}
	//char my_ip[16] = "25.72.35.65";
	char my_ip[16];
	for (int i=0;i< uData.myIP.length();i++)
	{
		my_ip[i] = uData.myIP[i];
	}
	cout << "Own IP:" << my_ip << endl;
	do{
		S.listening();
		S.getSequence(); 
		if(S.noerrror()&&S.itsMe(my_ip))
		{
			viewer V(1000, 900);
			if (V.IsInitOK())
			{
				V.RunAnimation(S.getAnim());
			}
			else
			{
				std::cout << "Error in allegro, animation skipped for this IP adress" << endl <<
					"Closing application" << endl;
				S.setQuit(true);
			}
			if(S.lastOne())
			{
				getUserSequence(S);
			}
		}
		else if (!S.noerrror())
		{
			std::cout << "Error in package YOU_GO, animation skipped for this IP adress" << endl <<
				"Closing application" << endl;
			S.setQuit(true);
		}
		Client C(S.getNext());
		C.startConnection(S.getNext());
		C.sendSeq(S.getMsg());
		S.closeSocket();
	} while (!S.getQuit());
	return 0;
}


int Callback(char *key, char *value, void *userData) {

	int errfl = ON;										//Dado que no se aceptan más de una misma llamada a un parametro, se utiliza un flag 
	userDataType *uData = (userDataType*)userData;		//para verificar que el parametro no fue llamado anteriormente.
	char*aux[] = { "255","255","255","255" };						//Se castea el puntero a void por portabilidad del Parser
	char aux2[255];
																	//unsigned int machines=0;

	if (key == NULL) {
		if (!strcmp(value, "help")) {		//Se agrego un help para el uso del programa.
			help();
			return -1;
		}
		else if (!strcmp(value, "inicia")) {
			if (uData->Flag->inicia == OFF) {
				uData->Flag->inicia = ON;
				uData->inicia = ON;
				errfl = OFF;
			}
			else {
				printf("Error: Multiple inicialization of parameters!!\n");
				return -1;
			}
		}
		else {
			printf("Error: Invalid parameter type argument given, use parameter 'help' for details.\n");
			return -1;
		}
	}


	if (!strcmp(key, "IP")) {
		if (uData->Flag->myIP == "OFF") {
			if (strchr(value, '.') != NULL) {		//Si contiene un punto, debe ser del formato xxx.xxx.x.xxx de IPv4
				strcpy(aux2, value);
				aux[0] = strtok(aux2, ".");			//En cuyo caso se separan los strings entre los puntos.
				aux[1] = strtok(NULL, ".");
				aux[2] = strtok(NULL, ".");
				aux[3] = strtok(NULL, ".");
				if ((aux[0] != NULL) && (isanumber(aux[0]))) {	//luego de separarlos se verifica que sean numeros
					if (aux[1] != NULL && (isanumber(aux[1]))) {
						if ((aux[2] != NULL) && (isanumber(aux[2]))) {
							if ((aux[3] != NULL) && (isanumber(aux[3]))) {
								uData->myIP = value;
								uData->Flag->myIP = "ON";
								errfl = OFF;
							}
							else {
								printf("Error: IP given is formatted wrong, use argument 'help' for details.\n");
								return -1;
							}
						}
						else {
							printf("Error: IP given is formatted wrong, use argument 'help' for details.\n");
							return -1;
						}
					}
					else {
						printf("Error: IP given is formatted wrong, use argument 'help' for details.\n");
						return -1;
					}
				}
				else {
					printf("Error: IP given is formatted wrong, use argument 'help' for details.\n");
					return -1;
				}
			}
			else {
				printf("Error: IP given is formatted wrong, use argument 'help' for details.\n");
				return -1;
			}
		}
		else {
			printf("Error: Multiple IP arguments!!\n");
			return -1;
		}
	}

	if (errfl == ON) {
		printf("Error: Invalid key -%s!\n", key);
		return (-1);
	}
	return 0;
}

int CheckParameters(userDataType *uData) {
	if (uData->Flag->myIP == "OFF") {
		printf("Error: No IP given.\n");
		return -1;
	}

	/*if (uData->Flag->sequence == "ON") {
	printf("Sequence chosen: %s\n", uData->sequence);
	uData->inicia = ON;
	}*/


	//If there was no error, print the chosen values.
	cout << "Your IP:" << uData->myIP << endl;

	return 0;
}

int isanumber(char* value) {		//No standard function to check if the value string was a double unless using sscanf. We made our own. 
	int fldash = 1;
	int flpoint = 1;
	for (int i = 0; i< (int)strlen(value); i++) {
		if (isdigit(value[i])); else if (value[i] == '.') if (flpoint == OFF) flpoint = ON; else return 0; else if (value[i] == '-') if (fldash == OFF) fldash = ON; else return 0; else return 0;
	}
	return 1;
}


void help(void) {									//Created for easy use to new users.
	printf("Welcome user!\n");
	printf("This text was written to help new users with the parameters and limitations of the program.\n");
	printf("\n Key Parameters: (Case sensitive)\n");
	printf("\n Use -IP  to define the IP of the computer you are using the program on. This argument is mandatory\n");
	printf("for the conection and program to work. It is the only non-optional argument.\n");
	printf("The format used is IPv4 xxx.xxx.xxx.xxx \n");
	printf("\nNon-Key Parameters: (Case sensitive)\n");
	printf("\n Use 'inicia' to define one of the PCs as the starter in the chain of connection.\n");
	printf("At least one PC must be chosen to start connection but no more than one of them should be chosen for the program to work.\n");
	printf("\nUse 'help' to access this menu. But you already knew that.\n");
	printf("\n The program runs an animation through the display of each computer one after another.\n");
	printf("This is done via internet conection between the computers running the program to run the animation.\n");
	printf("Once a sequence is finished the last computer can choose what the next animation and sequence is or end the program.\n");
	printf("To end the program just give the character 'Q' when the sequence is requested by the last computer.\n");
	printf("Press enter to exit...\n");

}
