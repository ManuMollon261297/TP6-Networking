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

int main(int argc, char* argv[]) // Param 1 (mandatorio) = IP propia
{								 // Param 2 (opcional) = Inicial
	userDataType uData = { NULL, "255.255.255.255", OFF, "C123"};
	userDataType Flags = { NULL, "OFF", OFF, "OFF"};
	uData.Flag = &Flags;
								 // Param 3 (opcional) = Sequencia , si no hay es 1,2,3,4,5...etc;
	if (parsecmdline(argc, argv, &Callback, &uData) != -1) {					//Parseo
		if (!CheckParameters(&uData)) {									//Verifica datos compatibles y los printea si no hay error

			if (!al_init())
			{
				exit(-1);
			}
			Server S(PORT_S);
			do {
				S.setTurno(YO); //revisar argv a ver si es el inicial o no, modificar S.turno segun esto
				S.setAnim('A'); //podria pasarse como parametro 
				char my_ip[16] = "25.72.35.65"; //llenar con el param 1 de ip propia
				S.listening();
				S.getSequence();
				if (S.noerrror() && S.itsMe(my_ip))
				{
					viewer V(1000, 900);
					V.RunAnimation(S.getAnim());
					if (S.lastOne())
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
			} while (!S.getQuit());
		}
	}
			return 0;
}

int
Callback(char *key, char *value, void *userData) {

	int errfl = ON;										//Dado que no se aceptan más de una misma llamada a un parametro, se utiliza un flag 
	userDataType *uData = (userDataType*)userData;		//para verificar que el parametro no fue llamado anteriormente.
	char*aux[] = { "255","255","255","255" };						//Se castea el puntero a void por portabilidad del Parser
	//char*aux2[255];														//aux se utiliza para la lectura de -color en formato R,G,B
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
				printf("Error: Multiple inicia parameters!!\n", key);
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
				aux[0] = strtok(value, ".");			//En cuyo caso se separan los strings entre los puntos.
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
			printf("Error: Multiple IP arguments!!\n", key);
			return -1;
		}
	}

	/*if (!strcmp(key, "SEQ")) {
		if (uData->Flag->sequence == "OFF")	 {
			if (value[0] >= 'A' && value[0] <= 'F') {
				if (strchr(value, ',') != NULL) {
					aux2[0] = strtok(value, ",");
					for (int i = 1; (aux2[i] != NULL) ;i++) {
						if (i >= 255) {
							cout << "ERROR: wrong sequence format. Sequence is too long." << endl;
							return -1;
						}
						aux[i] = strtok(NULL, ",");
						if (!isanumber(aux2[i])) {
							cout << "ERROR: wrong sequence format. PC numbers are separated by commas." << endl;
							return -1;
						}
						else if (atoi(aux[i])>255 || atoi(aux[i])<1) {
							cout << "ERROR: wrong sequence format. Max number of PCs is 255 and are numbered from 1 to 255." << endl;
							return -1;
						}else if(){
						
						}
						machines++;
					}
					while (machines > 0) {
						for (int i=0;i;) {

						}
						machines--;
					}
					
				}
			}
			else {
				printf("Error: Invalid sequence given, use 'help' for details.\n");
				return -1;
			}
			
		}
		else {
			printf("Error: Multiple sequence arguments!\n", key);
			return -1;
		}
		
	}*/

	
	if (errfl == ON) {
		printf("Error: Invalid key -%s!\n", key);
		return (-1);
	}
	return 0;
}

int
CheckParameters(userDataType *uData) {	
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
	for (int i = 0; i<strlen(value); i++) {
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
	printf("The format used is IPv4 xxx.xxx.xxx.xxx .\n");
	printf("\nNon-Key Parameters: (Case sensitive)\n");
	printf("\n Use 'inicia' to define one of the PCs as the starter in the chain of connection.\n");
	printf("At least one PC must be chosen to start connection but no more than one of them should be chosen for the program to work.\n");
	printf("\nUse 'help' to access this menu. But you already knew that.\n");
	//printf("\n -SEQ is reserved for the starter PC. There must be only one starter PC among the PCs that will connect.\n");
	//printf("When chosen the PC will begin the conection chain with the rest of the PCs using the program.\n");
	//printf("It also defines the starting sequence and starting animation of the chain.\n");
	//printf("The format of the sequence is: <animation character>,#,#,#,# where <animation character> is an ASCII\n");
	//printf("character between A and F representing the animation chosen. # is a number representing the order of the PC\n");
	//printf("which will display the animation, ordered from left to right.\n");
	printf("\n The program runs an animation through the display of each computer one after another.\n");
	printf("This is done via internet conection between the computers running the program to run the animation.\n");
	printf("Once a sequence is finished the last computer can choose what the next animation and sequence is or end the program.\n");
	printf("To end the program just give the character 'q' when the sequence is requested by the last computer.\n");
	

}