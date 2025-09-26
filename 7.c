/*
Name : 7.c
Author : Ishita Kar
Description:Write a simple program to print the created thread ids.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

        void *myThreadFunc(void *arg)
        {
                int id= *((int *)arg);
		pthread_t tid=pthread_self();
                printf("Thread ID: %ld\n",tid);
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

 Thread ID: 135614959711936
Thread ID: 135614942926528
Thread ID: 135614951319232
All Threads completed
______________________________________________________________________________
*/
