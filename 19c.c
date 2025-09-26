/*
Name : 19c.c
Author : Ishita Kar
Description:Create a FIFO by mknod system call
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	if(mknod("mypipe2",S_IFIFO|0777,0)==0)
	printf("FIFO created successfully \n");
	else
        printf("Error");
}

/*______________________________________________________________________________
 OUTPUT

FIFO created successfully

Terminal 1:
echo "Hello.." > mypipe2

Terminal 2:
Hello..
___________________________________________________________________________________
*/
