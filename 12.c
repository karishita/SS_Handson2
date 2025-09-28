/*
Name : 12.c
Author : Ishita Kar
Description: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main()
{
	if(!fork())
	{
		//child
	        pid_t pid=getppid();
		printf("Sending signal to parent process\n");
		fflush(stdout);
		sleep(2);
		kill(pid,SIGKILL);
		sleep(2);
		printf("Now child process with pid %d is orphan. Its parent process id is %d\n",getpid(),getppid());
		fflush(stdout);
		sleep(10);
	}

	else
	{
		//parent
		while(1)
		{
			printf("This is parent process with PID %d\n",getpid());
			fflush(stdout);
			sleep(2);
		}
		
	}
}

/*_____________________________________________________________________________
OUTPUT

  This is parent process with PID 4589
Sending signal to parent process
Killed
ishita@ishita-lin:~/handson_2$ Now child process with pid 4590 is orphan. Its parent process id is 1660
_______________________________________________________________________________
*/
