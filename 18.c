/*
Name : 18.c
Author : Ishita Kar
Description:program to find out total number of directories on the pwd.execute ls -l | grep ^d | wc
Date: 11th Sep, 2025.
_____________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	if(!fork())
	{
		close(1);
		dup2(fd1[1],1);
		close(fd1[0]);
		//close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execlp("ls","ls","-l",NULL);
	}
	else
	{
		if(!fork())
		{
		close(1);
		close(0);
		dup2(fd1[0],0);
		dup2(fd2[1],1);
		close(fd1[1]);
                close(fd2[0]);
		execlp("grep","grep","^d",NULL);

		}
		else
		{
                    close(0);
		    dup2(fd2[0],0);
		    close(fd2[1]);
		    close(fd1[0]);
		    close(fd1[1]);
		    execlp("wc","wc",NULL);
		}
	}
}
/*__________________________________________________________________________________
 OUTPUT
  0       0       0
___________________________________________________________________________________
*/
