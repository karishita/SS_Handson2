/*
Name : 29.c
Author : Ishita Kar
Description:Write a program to remove the message queue.
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
        msgctl(msgid,IPC_RMID,NULL);
	printf("message queue removed successfully \n");
}

/*___________________________________________________________________________
 OUTPUT

 message queue removed successfully
ishita@ishita-lin:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
___________________________________________________________________________
*/
