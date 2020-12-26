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
WSACleanup();
return;
}
SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
SOCKADDR_IN addrSrv;
addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
addrSrv.sin_family=AF_INET;
addrSrv.sin_port=htons(6000);
bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
listen(sockSrv,6);
char sendBuf[100];
char recvBuf[100];
char tempBuf[100];
SOCKADDR_IN addrClient;
int len=sizeof(SOCKADDR);
while(1)
{
printf("waiting for client\n");
SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
recv(sockConn,tempBuf,100,0);
if(tempBuf[0]!='q')
{
sprintf(recvBuf,"%s say: %s",inet_ntoa(addrClient.sin_addr),tempBuf);
printf("%s\n",recvBuf);
printf("please input your data,server:\n");
gets(sendBuf);
send(sockConn,sendBuf,strlen(sendBuf)+1,0);
}
else
{
printf("%s request to quit the chat platform",inet_ntoa(addrClient.sin_addr));
send(sockConn,"q",strlen("q")+1,0);
closesocket(sockConn);
break;
}
}
closesocket(sockSrv);
WSACleanup();
}