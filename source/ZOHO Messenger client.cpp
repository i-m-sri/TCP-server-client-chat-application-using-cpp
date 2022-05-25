#include<iostream>
#include<WinSock2.h>
#include<Windows.h>
#include<string>

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

#define SCK_VERSION 0X0202

using namespace std;

void setcolor(unsigned char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main()
{
	SOCKET sock;
	SOCKADDR_IN address;

	long ok;
	char MESSAGE[200];

	WSAData WSD;
	WORD Dllversion;
	Dllversion = MAKEWORD(2, 1);
	ok = WSAStartup(Dllversion, &WSD);
	setcolor(0x0b);
	std::cout << "\n ZOHO MESSENGER\n --------------\n\n";
	setcolor(0x07);
	while (true)
	{
		sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_family = AF_INET;
		address.sin_port = htons(10102);

		connect(sock,(SOCKADDR*)&address,sizeof(address));

		string msg;
		cout << " >> ";
		setcolor(0x0a);
		getline(cin,msg);
		setcolor(0x07);
		cout << "_____________________________________________________________________\n";
		const char* s = msg.c_str();
		ok = send(sock, s, 1024, NULL);

		ok = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		string reply;
		reply = MESSAGE;
		cout << "\n Mentor  : ";
		setcolor(0x0a);
		cout << reply << "\n\n";
		setcolor(0x07);
	}
}
