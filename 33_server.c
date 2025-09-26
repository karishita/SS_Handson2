/*
Name : 33_server.c
Author : Ishita Kar
Description:Write a program to communicate between two machines using socket.
(Server Program)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	struct sockaddr_in serv,cli;
	int sd,sz,nsd;
	char buf[30];
	sd=socket(AF_INET,SOCK_STREAM,0);
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(5056);
	bind(sd,(void*)(&serv),sizeof(serv));
	listen(sd,5);
	sz=sizeof(cli);
	nsd=accept(sd,(void *)(&cli),&sz);
	read(nsd,buf,sizeof(buf));
	printf("Message from Client %s\n",buf);
	write(nsd,"ACK from Server\n",17);
}

/*___________________________________________________________________________
 OUTPUT

 Message from Client Hello from Client

 ________________________________________________________________________________
