/*
Name : 32a_b.c
Author : Ishita Kar
Description:Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
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
	// Semaphore
        union semun arg;
        int key_s,semid;
        key_s=ftok(".",'c');
        semid=semget(key_s,1,0777);
	int val=semctl(semid,0,GETVAL);
	printf("The semaphore ID is %d \n",semid);
        printf("the   value of semaphore is %d\n",val);

	//Using the semaphore
	struct sembuf op;
	op.sem_num=0;
	op.sem_op=-1;
	op.sem_flg=0;
        printf("Before entering critical section\n");
	// wait 
	semop(semid,&op,1);

        //Critical Section
	printf("Press enter to take ticket: ");
        getchar();
	int key_m,shmid;
        char *data;
        key_m=ftok(".",'b');
        shmid=shmget(key_m,1024,IPC_CREAT|0744);
        data=shmat(shmid,0,0);
        int *p= (int *) data;
	*p=*p-1;
	printf("New Ticket No is : %d\n",*data);
        printf("Ticket taken \n");
	printf("Enter to Unlock");
	getchar();
	//signal
	op.sem_op=1;
	semop(semid, &op,1);

}

 /*___________________________________________________________________________
  OUTPUT

 Terminal 1:
 -------------------------------------------------------------------------------
The semaphore ID is 2
the   value of semaphore is 1
Before entering critical section
Press enter to take ticket:
-------------------------------------------------------------------------------
Terminal 2:
The semaphore ID is 2
the   value of semaphore is 0
Before entering critical section

--------------------------------------------------------------------------------Terminal 1:
New Ticket No is : 9
Ticket taken 
Enter to Unlock
-------------------------------------------------------------------------------
Terminal 2:
Press enter to take ticket:
New Ticket No is : 8
Ticket taken
Enter to Unlock
____________________________________________________________________________
*/


