/*
Name : 10c.c
Author : Ishita Kar
Description:Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigfpe_handler(int sig)
{
        printf("Caught signal %d . Exiting gracefully.\n",sig);
        exit(1);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler=sigfpe_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sigaction(SIGFPE,&sa,NULL);
        printf("Generating floating point exception \n");
        int x=5/0; // divide by 0

        return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Generating floating point exception
Caught signal 8 . Exiting gracefully.
______________________________________________________________________________
*/
