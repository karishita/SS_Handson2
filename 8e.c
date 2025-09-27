/*
Name : 8e.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
e. SIGALRM(using settimer system call)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
void sigalrm_handler(int sig)
{
        printf("Caught SIGALRM . Timer expired\n");
        exit(1);
}

int main()
{
	struct itimerval timer;
        signal(SIGALRM,sigalrm_handler);
        printf("Setting Alarm for 5 sec...\n");
        timer.it_value.tv_sec=5;
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL,&timer,NULL);

       while(1)
       {
               printf("Working \n");
               sleep(1);
       }
       printf("Program finished \n");
        return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Setting Alarm for 5 sec...
Working
Working
Working
Working
Working
Caught SIGALRM . Timer expired
______________________________________________________________________________
*/
