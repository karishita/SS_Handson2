/*
Name : 6.c
Author : Ishita Kar
Description:Write a simple program to create three threads.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

	void *myThreadFunc(void *arg)
	{
		int id= *((int *)arg);
		printf("Hello from thread %d\n",id);
		return NULL;
	}


int main()
{
	pthread_t threads[3];
	int thread_ids[3];
	for(int i=0;i<3;i++)
	{
		thread_ids[i]=i+1;
		pthread_create(&threads[i],NULL,myThreadFunc,&thread_ids[i]);
	}

	for(int i=0;i<3;i++)

	{
		pthread_join(threads[i],NULL);
	}
	printf("All Threads completed\n");
	return 0;
}

/*____________________________________________________________________________
 OUTPUT

 Hello from thread 1
Hello from thread 2
Hello from thread 3
All Threads completed
_______________________________________________________________________________
*/
