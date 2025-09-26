/*
Name : 30a.c
Author : Ishita Kar
Description:Write a program to create a shared memory and  write some data to the shared memory
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
	printf("Enter the text: ");
	scanf("%[^\n]",data);
}

/*____________________________________________________________________________
 * OUTPUT
 
 Enter the text: Hello There

ishita@ishita-lin:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x62050301 0          ishita     744        1024       0
------------------------------------------------------------------------------
*/
