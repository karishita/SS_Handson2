/*
Name : 10a.c
Author : Ishita Kar
Description:Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigsegv_handler(int sig)
{
        printf("Caught signal %d (Segmentation Fault). Exiting gracefully.\n",sig);
        exit(1);
}

int main()
{
	struct sigaction sa;
        sa.sa_handler=sigsegv_handler;
	sigemptyset(&sa.sa_mask);
        sa.sa_flags=0;
	sigaction(SIGSEGV,&sa,NULL);
        int *ptr=NULL;
        *ptr=42; // segmentation fault

        return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Caught signal 11 (Segmentation Fault). Exiting gracefully.
_______________________________________________________________________________
*/
