/*
Name : 32c.c
Author : Ishita Kar
Description:Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    // Semaphore
    union semun arg;
    int key_s, semid;
    key_s = ftok(".", 'c');
    semid = semget(key_s, 1, 0);

    int val = semctl(semid, 0, GETVAL);
    printf("The semaphore ID is %d\n", semid);
    printf("The value of semaphore is %d\n", val);

    // Using the semaphore
    struct sembuf op;

    // Wait operation (decrement)
    op.sem_num = 0;
    op.sem_op = -1;  // wait / P
    op.sem_flg = 0;

    printf("Before entering critical section\n");
    semop(semid, &op, 1); // acquire resource
   
    int key_m, shmid;
    char *data;
    key_m = ftok(".", 'b');
    shmid = shmget(key_m, 1024, IPC_CREAT | 0744);
    data = shmat(shmid, 0, 0);
    int *p=(int *) data;
    if(*p==0)
    {
    *p=10;
    }

    // Critical Section
    printf("Press enter to take ticket: ");
    getchar();

  
    *p = *p - 1;  // take a ticket
    printf("New Ticket No is: %d\n", *p);
    printf("Ticket taken\n");

    printf("Enter to unlock: ");
    getchar();

    // Signal operation (increment)
    op.sem_op = 1;  // signal / V
    semop(semid, &op, 1); // release resource

    return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Terminal 1:
 Before entering critical section
Press enter to take ticket:
-------------------------------------------------------------------------------
Terminal 2:

The semaphore ID is 0
The value of semaphore is 1
Before entering critical section
Press enter to take ticket:
--------------------------------------------------------------------------------Terminal 3:
The semaphore ID is 0
The value of semaphore is 0
Before entering critical section
________________________________________________________________________________*/
