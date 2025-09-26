/*
Name : 34a_server.c
Author : Ishita Kar
Description:Write a program to create a concurrent server using fork(server)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
int main()
{
	struct sockaddr_in serv,cli;
	int sd,nsd,sz;
	char buf[100];

	sd=socket(AF_INET,SOCK_STREAM,0);
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(5056);
	bind(sd, (void *) &serv,sizeof(serv));
	listen(sd,5);
	printf("Server listening on port 5056.....\n");
	while(1)
	{
		sz=sizeof(cli);
		nsd=accept(sd,(void *) &cli, &sz);
		if(!fork()) //child process handles client
	      {
		      close(sd);
		      int n=read(nsd,buf,sizeof(buf));
		      buf[n]='\0';
		      printf("Message from Client : %s\n",buf);

		      write(nsd,"ACK from Server \n", strlen("ACK from Server \n"));
				      close(nsd);
				      exit(0);
	      }
		else
		{
			close(nsd);
		}
	}
}


/*_____________________________________________________________________________
 OUTPUT

 Server listening on port 5056.....
Message from Client : Hello from Client

Message from Client : Hello from Client

Message from Client : Hello from Client
_______________________________________________________________________________
*/
