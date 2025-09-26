/*
Name : 1a.c
Author : Ishita Kar
Description:Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second using ITIMER_REAL
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
	printf("ITIMER_REAL triggered (SIGALRM)\n");
}
int main()
{
	struct itimerval timer;
	signal(SIGALRM,handler);
	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;
	timer.it_interval.tv_sec=10;
	timer.it_interval.tv_usec=10;
	setitimer(ITIMER_REAL,&timer,NULL);
	while(1)
	pause();
        return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
ITIMER_REAL triggered (SIGALRM)
________________________________________________________________________________*/
