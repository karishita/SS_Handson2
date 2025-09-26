/*
Name : 31a.c
Author : Ishita Kar
Description:Write a program to create a binary semaphore and initialize value to the semaphore.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>

union semun {
    int val;                
    struct semid_ds *buf;   
    unsigned short *array;  
    struct seminfo *__buf;  
};

int main()
{
	union semun arg;
	int key,semid;
	key=ftok(".",'a');
	semid=semget(key,1,IPC_CREAT|0777);
	arg.val=1;
	semctl(semid,0,SETVAL,arg);
	int val=semctl(semid,0,GETVAL);
	printf("The value assigned to semaphore is : %d\n",val);
}

/*____________________________________________________________________________
 OUTPUT

 The value assigned to semaphore is : 1
------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x61050301 0          ishita     777        1   
_______________________________________________________________________________
*/
