/*
Name : 1b.c
Author : Ishita Kar
Description:Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second using ITIMER_VIRTUAL
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
        printf("ITIMER_VIRTUAL triggered (SIGVTALRM)\n");
}

int main()
{
        struct itimerval timer;
        signal(SIGVTALRM,handler);
        timer.it_value.tv_sec=10;
        timer.it_value.tv_usec=10;
        timer.it_interval.tv_sec=10;
        timer.it_interval.tv_usec=10;
        setitimer(ITIMER_VIRTUAL,&timer,NULL);
        while(1)
	{

	}
        return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 ITIMER_VIRTUAL triggered (SIGVTALRM)
ITIMER_VIRTUAL triggered (SIGVTALRM)
ITIMER_VIRTUAL triggered (SIGVTALRM)
ITIMER_VIRTUAL triggered (SIGVTALRM)
ITIMER_VIRTUAL triggered (SIGVTALRM)
ITIMER_VIRTUAL triggered (SIGVTALRM)
_______________________________________________________________________________
*/
