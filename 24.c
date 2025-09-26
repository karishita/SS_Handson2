/*
Name : 24.c
Author : Ishita Kar
Description:Write a program to create a message queue and print the key and message queue id.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	int msgid,size;
	key_t key;
	struct msg{
		long int mtype;
		char message[80];
	} mq;
	key=ftok(".",'a');
	msgid=msgget(key,0777| IPC_CREAT);
	printf("key : %d\n",key);
	printf("Message Queue ID : %d\n",msgid);
}

/*___________________________________________________________________________
OUTPUT 
key : 1627718401
Message Queue ID : 0
______________________________________________________________________________
*/

