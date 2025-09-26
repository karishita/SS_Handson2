/*
Name : 1b.c
Author : Ishita Kar
Description:Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second using ITIMER_PROF
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>


void handler(int sig)
{
        printf("ITIMER_PROF triggered (SIGPROF)\n");
}

int main()
{
        struct itimerval timer;
        signal(SIGPROF,handler);
        timer.it_value.tv_sec=10;
        timer.it_value.tv_usec=10;
        timer.it_interval.tv_sec=10;
        timer.it_interval.tv_usec=10;
        setitimer(ITIMER_PROF,&timer,NULL);
        while(1)
        {
		for(volatile int i=0;i<1000000;i++);
        }
        return 0;
}
/*_____________________________________________________________________________
 OUTPUT

 ITIMER_PROF triggered (SIGPROF)
ITIMER_PROF triggered (SIGPROF)
ITIMER_PROF triggered (SIGPROF)
ITIMER_PROF triggered (SIGPROF)
ITIMER_PROF triggered (SIGPROF)
_______________________________________________________________________________
*/
