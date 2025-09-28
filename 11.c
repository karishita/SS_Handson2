/*
Name : 11.c
Author : Ishita Kar
Description:Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use sigaction system call.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void sigint_handler(int sig)
{
        printf("caught signal %d by custom handler....\n",sig);

}

int main()
{
struct sigaction sa;
sa.sa_handler=SIG_IGN;
sigemptyset(&sa.sa_mask);
sa.sa_flags=0;
sigaction(SIGINT,&sa,NULL);

printf("Program Running\n");

for(int i=0;i<10;i++)
{
printf("Working\n");
sleep(2);
}
sa.sa_handler=SIG_DFL;
sigaction(SIGINT,&sa,NULL);

printf("Signal handler reset to default.\n");
while(1)
{
        printf("Working\n");
        sleep(1);
}
return 0;
}

/*___________________________________________________________________________
 OUTPUT

 Program Running
Working
Working
^CWorking
^CWorking
Working
Working
Working
Working
^CWorking
Working
Signal handler reset to default.
Working
Working
Working
^C
_______________________________________________________________________________
*/
