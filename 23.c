/*
Name : 23.c
Author : Ishita Kar
Description:Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/stat.h>
int main()
{
struct rlimit rl;
getrlimit(RLIMIT_NOFILE,&rl);
printf("Maximum number of files that can be opened within a process\n");
printf("soft limit : %ld\n",rl.rlim_cur);
printf("Hard limit : %ld\n",rl.rlim_max);

int fd=open("mypipe",O_RDONLY|O_NONBLOCK);
int pipe_size=fcntl(fd,F_GETPIPE_SZ);
printf("FIFO buffer size: %d bytes \n",pipe_size);
close(fd);
return 0;
}

/*____________________________________________________________________________
 OUTPUT
 Maximum number of files that can be opened within a process
soft limit : 1024
Hard limit : 1048576
FIFO buffer size: 65536 bytes
_______________________________________________________________________________
*/
