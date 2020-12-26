#include<winsock2.h>
#include<stdio.h>
#include<string.h>
//#pragma comment(lib,"ws2_32.lib")
void main()
{
WORD wVersionRequested;
WSADATA wsaData;
int err;
wVersionRequested=MAKEWORD(1,1);
err=WSAStartup(wVersionRequested,&wsaData);
if(err!=0)
{
return;
}
if(LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1)
{
return;
}
while(1)
{
SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
SOCKADDR_IN addrSrv;
addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
addrSrv.sin_family=AF_INET;
addrSrv.sin_port=htons(6000);
char sendBuf[100];
char tempBuf[100];
char recvBuf[100];
int len=sizeof(SOCKADDR);
connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));

printf("please input your data,client:\n");
gets(sendBuf);
printf("waiting for server\n");
send(sockClient,sendBuf,sizeof(sendBuf)+1,0);
recv(sockClient,tempBuf,100,0);
if(tempBuf[0]!='q')
{
sprintf(recvBuf,"server say: %s",tempBuf);
printf("%s\n",recvBuf);
}
else
{
printf("the server has been closed!\n");
send(sockClient,"q",strlen("q")+1,0);
break;
}
}
// closesocket(sockClient);
WSACleanup();
}