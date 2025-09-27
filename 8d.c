/*
Name : 8d.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
d. SIGALRM(using alarm system call)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void sigalrm_handler(int sig)
{
        printf("Caught SIGALRM . Timer expired\n");
        exit(1);
}

int main()
{
        signal(SIGALRM,sigalrm_handler);
	printf("Setting Alarm for 5 sec...\n");
	alarm(5);

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
________________________________________________________________________________*/
