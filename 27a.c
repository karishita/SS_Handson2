/*
Name : 27a.c
Author : Ishita Kar
Description:Write a program to receive messages from the message queue.
a. with 0 as a flag

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
        msgid=msgget(key,0);
        printf("Enter the message type to recieve :");
	scanf("%ld",&mq.mtype);
	msgrcv(msgid,&mq,sizeof(mq.message),mq.mtype,0);
	printf("Message type : %ld\n",mq.mtype);
	printf("Message Text : %s\n",mq.message);
}

/*_____________________________________________________________________________
 OUTPUT

 Enter the message type to recieve :3
Message type : 3
Message Text : Hello World
______________________________________________________________________________
*/
