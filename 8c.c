/*
Name : 8c.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
a. SIGFPE
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
        signal(SIGFPE,sigfpe_handler);
        printf("Generating floating point exception \n");
        int x=5/0; // divide by 0

        return 0;
}
/*_____________________________________________________________________________
 OUTPUT

 Generating floating point exception
Caught signal 8 . Exiting gracefully.
_____________________________________________________________________________
*/
