/*
Name : 30c.c
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
	data=shmat(shmid,0,0);
	printf("Enter Text: ");
        scanf("%[^\n]",data);
        printf("data written:  %s\n",data);

	//Detaching
	if(shmdt(data)==-1)
		printf("Detaching failed\n");
	else
		printf("Detatched successfully\n");
}


