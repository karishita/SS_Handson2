/*
Name : 30d.c
Author : Ishita Kar
Description:Write a program to create a shared memory and detach the shared memory.
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
        shmid=shmget(key,1024,0);
        if(shmctl(shmid,IPC_RMID,NULL)==-1)
		printf("shmctl failed\n");
	else
		printf("Shared Memory Removed \n");
}

/*____________________________________________________________________________
 *
 OUTPUT

 Shared Memory Removed
ishita@ishita-lin:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

____________________________________________________________________________
*/
