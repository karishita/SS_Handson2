/*
Name : 32_memory.c
Author : Ishita Kar
Description:Shared Memory Creation for Question 32
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
        int key,shmid;
        char *data;
        key=ftok(".",'b');
        shmid=shmget(key,1024,IPC_CREAT|0744);
        data=shmat(shmid,0,0);
        printf("Enter the ticket No: ");
        scanf("%d",(int *)data);
	printf("You entered: %d\n", *data);
}

/*_____________________________________________________________________________
 OUTPUT

Enter the ticket No: 10
You entered: 10
________________________________________________________________________________*/




