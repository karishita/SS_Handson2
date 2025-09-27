/*
Name : 8a.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
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
	
}

int main()
{
signal(SIGINT,sigint_handler);
printf("Program Running\n");
while(1)

{
printf("Working\n");
sleep(2);
}
return 0;
}

/*___________________________________________________________________________
 OUTPUT

 Program Running
Working
Working
Working
^Ccaught signal 2....
Working
Working
^Ccaught signal 2....
_____________________________________________________________________________
*/
