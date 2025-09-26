/*
Name : 30b.c
Author : Ishita Kar
Description: Write a program to create a shared memory. Attach with O_RDONLY and check whether you are able to overwrite.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int key,shmid;
	char* data;
	key=ftok(".",'b');
	shmid=shmget(key,1024,0);
	data=shmat(shmid,0,SHM_RDONLY);
	printf("Text from shared memory: %s\n",data);

	printf("Enter new Text: ");
	scanf("%[^\n]",data);

}

/*___________________________________________________________________________
 OUTPUT

 Text from shared memory: Hello There
Enter new Text: HI
Segmentation fault (core dumped)
____________________________________________________________________________
*/
