#include <WinSock2.h>  
#include <stdio.h> 
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib")  

void Client(int &rep)
{
	//加载套接字 
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed to load Winsock");
		return;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	//创建套接字  
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == sockClient) {
		printf("Socket() error:%d", WSAGetLastError());
		return;
	}

	//向服务器发出连接请求  
	if (connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET) {
		printf("Connect failed:%d", WSAGetLastError());
		return;
	}

	//发送数据  
	std::string data;
	std::string Data;
	std::getline(std::cin, data);
	const char *sendData;
	sendData = data.c_str();
	send(sockClient, sendData, strlen(sendData), 0);

	char recData[255];
	int ret = recv(sockClient, recData, 255, 0);
	if (ret>0) {
		recData[ret] = 0x00;
		printf(recData);
		Data = recData;
		memset(recData, 0, 255 * sizeof(char));
	}
	rep = ret;//rep为mian函数中的循环的判断标准，注意本函数的rep参数是引用
			  //关闭套接字
	if (Data == "BYE\n")//BYE为本人设置的终止字符，并无任何要求，\n为换行符
	{
		closesocket(sockClient);
		WSACleanup();
		rep = 0;
	}
}

void main()
{
	int n = 1;
	while (n)
	{
		Client(n);
	}
}