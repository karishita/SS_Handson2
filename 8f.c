/*
Name : 8d.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM(using alarm system call)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>
void sigvtalrm_handler(int sig)
{
        printf("Caught SIGVTALRM .Virtual timer expired\n");
        exit(1);
}

int main()
{
	struct itimerval timer;

        signal(SIGVTALRM,sigvtalrm_handler);
        printf("Setting Alarm for 1 micro  sec...\n");
        timer.it_value.tv_sec=0;
        timer.it_value.tv_usec=1;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_VIRTUAL,&timer,NULL);
       for(volatile int i=0;i<10000000000000000;i++)
       {
               printf("Working \n");
	       fflush(stdout);
               sleep(1);
       }
       printf("Program finished \n");
        return 0;
}

/*___________________________________________________________________________
 OUTPUT
Setting Alarm for 1 micro  sec...
 Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Working
Caught SIGVTALRM .Virtual timer expired
___________________________________________________________________________-__
*/
