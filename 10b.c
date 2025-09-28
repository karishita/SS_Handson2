/*
Name : 10b.c
Author : Ishita Kar
Description:Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void sigint_handler(int sig)
{
        printf("caught signal %d....\n",sig);
	exit(1);

}

int main()
{
struct sigaction sa;
sa.sa_handler=sigint_handler;
sigemptyset(&sa.sa_mask);
sa.sa_flags=0;
sigaction(SIGINT,&sa,NULL);
printf("Program Running\n");
while(1)

{
printf("Working\n");
sleep(2);
}
return 0;
}


/*_____________________________________________________________________________
 OUTPUT

 Program Running
Working
Working
Working
^Ccaught signal 2....
--------------------------------------------------------------------------------*/
