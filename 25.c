/*
Name : 25.c
Author : Ishita Kar
Description: Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
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
	struct ipc_perm perm= buf.msg_perm;
    printf("a. Access permissions: %o\n", perm.mode & 0777);


    printf("b. UID (owner): %d, GID (owner): %d\n", perm.uid, perm.gid);

   
    printf("c. Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("   Time of last message received: %s", ctime(&buf.msg_rtime));

    
    printf("d. Time of last change: %s", ctime(&buf.msg_ctime));

    
    printf("e. Current size of queue (bytes): %lu\n", buf.__msg_cbytes);

   
    printf("f. Number of messages: %lu\n", buf.msg_qnum);

    
    printf("g. Maximum bytes allowed: %lu\n", buf.msg_qbytes);

 
    printf("h. PID of last msgsnd: %d, PID of last msgrcv: %d\n", buf.msg_lspid, buf.msg_lrpid);

    return 0;

}

/*_____________________________________________________________________________
 OUTPUT

 a. Access permissions: 777
b. UID (owner): 1000, GID (owner): 1000
c. Time of last message sent: Sat Sep 20 18:26:01 2025
   Time of last message received: Sat Sep 20 18:26:01 2025
d. Time of last change: Sat Sep 20 17:50:06 2025
e. Current size of queue (bytes): 2
f. Number of messages: 2
g. Maximum bytes allowed: 16384
h. PID of last msgsnd: 6988, PID of last msgrcv: 6977
______________________________________________________________________________
*/
