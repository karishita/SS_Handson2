/*
Name : 32d.c
Author : Ishita Kar
Description:Write a program to implement semaphore to protect any critical section.
d.remove the created semaphore
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    int key_s = ftok(".", 'c');
    int semid = semget(key_s, 1, 0); 

    if (semid == -1) {
        printf("Semaphore not found\n");
        return 1;
    }

    // Remove the semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        printf("Failed to remove semaphore\n");
        return 1;
    }

    printf("Semaphore removed successfully\n");
    return 0;
}

/*____________________________________________________________________________
 OUTPUT

 Semaphore removed successfully
------ Semaphore Arrays --------
key        semid      owner      perms      nsems 

______________________________________________________________________________
*/
