/*
Name : 26.c
Author : Ishita Kar
Description:Write a program to send messages to the message queue. Check $ipcs -q
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
        printf("Enter Message Type: \n");
	scanf("%ld",&mq.mtype);
	getchar();

	printf("Enter Message Text:");
	scanf("%[^\n]",mq.message);
	size=strlen(mq.message);
	msgsnd(msgid,&mq,size+1,0);

}

/*____________________________________________________________________________
 OUTPUT

 Enter Message Type:
3
Enter Message Text:Hello World
ishita@ishita-lin:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x61050301 0          ishita     777        14           3
____________________________________________________________________________
*/


