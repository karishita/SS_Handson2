/*
Name : 17a.c
Author : Ishita Kar
Description:program to execute ls -l | wc using dup
Date: 11th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];
	pipe(fd);
	if(!fork())
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		execlp("ls","ls",NULL);
	}
	else
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
		execlp("wc","wc",NULL);
	}
}

/*_____________________________________________________________________________
 OUTPUT

  10       9      67
_______________________________________________________________________________
*/
