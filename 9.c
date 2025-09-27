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
signal(SIGINT,sigint_handler);
printf("Program Running\n");

for(int i=0;i<10;i++)
{
printf("Working\n");
sleep(2);
}
signal(SIGINT,SIG_DFL);
printf("Signal handler reset to default.\n");
while(1)
{
	printf("Working\n");
	sleep(1);
}
return 0;
}

/*____________________________________________________________________________
 Program Running
Working
Working
Working
^Ccaught signal 2 by custom handler....
Working
Working
^Ccaught signal 2 by custom handler....
Working
Working
Working
Working
Working
Signal handler reset to default.
Working
Working
Working
Working
^C
________________________________________________________________________________*/
