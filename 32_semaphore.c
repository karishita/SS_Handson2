/*
Name : 32_semaphore.c
Author : Ishita Kar
Description:Semaphore Creation for Question 32
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>


union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main()

{
        //Creating Semaphore
        union semun arg;
        int key_s,semid;
        key_s=ftok(".",'c');
        semid=semget(key_s,1,IPC_CREAT|0777);
	arg.val=1;
	semctl(semid,0,SETVAL,arg);
        int val=semctl(semid,0,GETVAL);
        printf("The semaphore ID is %d \n",semid);
        printf("the initial  value of semaphore is %d\n",val);
}

/*__________________________________________________________________________
OUTPUT
  The semaphore ID is 2 
the initial  value of semaphore is 1
_____________________________________________________________________________
*/
