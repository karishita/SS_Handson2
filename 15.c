/*
Name : 15.c
Author : Ishita Kar
Description:program to send some data from parent to the child process.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	char buf[30];
        pipe(fd);
	if(!fork())
	{
		close(fd[1]);
		read(fd[0],buf,26);
		printf("The message from parent  is:  %s\n",buf);
	}
	else
	{
              close(fd[0]);
	      write(fd[1],"Hello there from parent \n",26);
	}
	return 0;
}

/*__________________________________________________________________________________
 The message from parent  is:  Hello there from parent
 ___________________________________________________________________________________
 */
