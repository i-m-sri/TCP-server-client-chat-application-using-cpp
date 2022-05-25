#include<iostream>  
#include<WinSock2.h>   //header file for handling sockets
#include<Windows.h>
#include<string>

#pragma comment(lib,"ws2_32.lib")   //adding ws2_32 library to get function definitions of Winsock2

#define SCK_VERSION 0X0202      //define socket version

using namespace std;

//fuction to change the colour of the output text
void setcolor(unsigned char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	SOCKET Connect;        //declaring a connection socket
	SOCKET listen_socket;  //declaring a listening socket
	SOCKADDR_IN address;   //declaring a strucuture variable for sockaddr_in
	int address_size = sizeof(address);   //initialising the size of sockadrr_in structure to a integer variable

	long ok;  //variable to hold random value returned after any soecket function is called;
	char MESSAGE[200];  //variable to store incoming messages

	WSAData WSD;    //as we are using windows os we need to declare wsadata variable
	WORD Dllversion;     //vaiable to store the version information
	Dllversion = MAKEWORD(2, 1);   //initialising varsion to declared variable
	ok = WSAStartup(Dllversion, &WSD);     //assin

	Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);      //initialising the connection socket
	address.sin_addr.s_addr = inet_addr("127.0.0.1");         //assinging device address to the s_addr 
	address.sin_family = AF_INET;                             //initialising the ip version 
	address.sin_port = htons(10102);                          //initialisng any random port with host to network function

	listen_socket= socket(AF_INET, SOCK_STREAM, NULL);        //initialising listening socket
	bind(listen_socket, (SOCKADDR*)&address, sizeof(address));//binging the listenting with our system process
	listen(listen_socket, SOMAXCONN);                         //listen function used to listen the incoming sockets it has limit of clients as SOMAXCONN
	setcolor(0x0b);
	std::cout << "\n ZOHO MESSENGER\n --------------\n";
	setcolor(0x07);
	while (true)                                              //loop for doing a chat session
	{
		if (Connect = accept(listen_socket, (SOCKADDR*)&address, &address_size))    
		{
			ok = recv(Connect, MESSAGE, sizeof(MESSAGE), NULL); //receiving incoming message
			string msg;
			msg = MESSAGE;
			cout << "\n Student : ";
			setcolor(0x0a);
			cout << msg << "\n\n";
			setcolor(0x07);

			string reply;
			cout << " >> ";
			setcolor(0x0a);
			getline(cin,reply);
			setcolor(0x07);
			cout << "_____________________________________________________________________\n";
			const char* s = reply.c_str();
			ok = send(Connect, s, 1024, NULL);   //sending our response
		}
	}
}