/*
Name : 3.c
Author : Ishita Kar
Description:Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
	struct rlimit limit;

	limit.rlim_cur=2;
	limit.rlim_max=2;
	
	setrlimit(RLIMIT_CPU,&limit);
	printf("CPU Limit set to 2 seconds. Running loop...\n");
	while(1)
	{

	}

	return 0;
}

/*_____________________________________________________________________________
OUTPUT

CPU Limit set to 2 seconds. Running loop...
Killed
______________________________________________________________________________
*/


