/*
Name : 14.c
Author : Ishita Kar
Description:program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	char buf[50];
	pipe(fd);
	printf("writing to the pipe...\n");
	write(fd[1],"Hello..\n",9);
	getchar();
	printf("Reading from the pipe\n");
	read(fd[0],buf,9);
	printf("The message is %s\n",buf);
	return 0;
}

/*__________________________________________________________________________________
 Output

writing to the pipe...

Reading from the pipe
The message is Hello..

__________________________________________________________________________________
