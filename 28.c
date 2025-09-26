/*
Name : 28.c
Author : Ishita Kar
Description: Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
        struct msqid_ds buf;
	msgctl(msgid,IPC_STAT,&buf);
	printf("Current permissions %o\n",buf.msg_perm.mode & 0777);
	unsigned int new;
	printf("enter new permissions in octal \n");
	scanf("%o",&new);
	buf.msg_perm.mode=(buf.msg_perm.mode & ~0777) | (new & 0777);
	msgctl(msgid,IPC_SET,&buf);
        printf("Permissions successfully changed to: %o\n", buf.msg_perm.mode &0777);
	return 0;
}

/*___________________________________________________________________________
 OUTPUT

 Current permissions 777
enter new permissions in octal
664
Permissions successfully changed to: 664


Access permissions: 664
______________________________________________________________________________
*/
