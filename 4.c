/*
Name : 4.c
Author : Ishita Kar
Description:Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>   
#include <sys/wait.h> 
static inline uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main()
{
	if(!fork())
	{
		 uint64_t start, end;

                  start = rdtsc();

		  for(volatile int i=1;i<=100;i++)
		  {
			  getppid();
		  }

		  end=rdtsc();

		  printf("Cycles taken : %llu\n",(unsigned long long)(end-start));
		  return 0;
	}
	else
	{
              wait(0);
	}
}
/*______________________________________________________________________________
 *
OUTPUT
Cycles taken : 105162
________________________________________________________________________________*/
