/*
Name : 34b_client.c
Author : Ishita Kar
Description:Write a program to create a concurrent server using pthread_create(client)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    struct sockaddr_in serv;
    int sd;
    char buf[30];
    int n;

    sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    serv.sin_port = htons(5056);

    connect(sd, (struct sockaddr *) &serv, sizeof(serv));

    // Send message
    write(sd, "Hello from Client\n", strlen("Hello from Client\n"));

    // Receive message
    n = read(sd, buf, sizeof(buf) - 1);
    buf[n] = '\0';   

    printf("Message from Server: %s\n", buf);

    close(sd);
    return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Message from Server: Hello from Client
_______________________________________________________________________________
*/
