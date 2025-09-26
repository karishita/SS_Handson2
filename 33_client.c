/*
Name : 33_client.c
Author : Ishita Kar
Description:Write a program to communicate between two machines using socket.
(Client Program)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	struct sockaddr_in serv;
	int sd;
	char buf[30];
	sd=socket(AF_INET,SOCK_STREAM,0);
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(5056);
	connect(sd,(void *)(&serv),sizeof(serv));
	write(sd,"Hello from Client\n",19);
	read(sd,buf,sizeof(buf));
	printf("Message from Server %s\n",buf);
}


/*____________________________________________________________________________
OUTPUT

  Message from Server ACK from Server

 _____________________________________________________________________________
