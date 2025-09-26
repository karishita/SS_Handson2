/*
Name : 8a.c
Author : Ishita Kar
Description:Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
 
void sigsegv_handler(int sig)
{
	printf("Caught signal %d (Segmentation Fault). Exiting gracefully.\n",sig);
	exit(1);
}

int main()
{
	signal(SIGSEGV,sigsegv_handler);
	
	int *ptr=NULL;
	*ptr=42; // segmentation fault
	
	return 0;
}
/*_____________________________________________________________________________
 OUTPUT

 Caught signal 11 (Segmentation Fault). Exiting gracefully.
_____________________________________________________________________________

*/
