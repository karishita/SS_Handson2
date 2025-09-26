/*
Name : 5.c
Author : Ishita Kar
Description:Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

int main() {
    struct rlimit limit;
    struct sysinfo info;

    printf("System Limitations:\n\n");

    
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("a. Maximum length of arguments to exec: %ld bytes\n",
           (arg_max != -1) ? arg_max : 0);

    
    if (getrlimit(RLIMIT_NPROC, &limit) == 0)
        printf("b. Maximum number of simultaneous processes per user: soft = %ld, hard = %ld\n",
               (long)limit.rlim_cur, (long)limit.rlim_max);
    else
        printf("b. Maximum number of simultaneous processes per user: Not available\n");

    
    long ticks = sysconf(_SC_CLK_TCK);
    printf("c. Number of clock ticks per second: %ld\n", (ticks != -1) ? ticks : 0);

    
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0)
        printf("d. Maximum number of open files: soft = %ld, hard = %ld\n",
               (long)limit.rlim_cur, (long)limit.rlim_max);
    else
        printf("d. Maximum number of open files: Not available\n");

   
    long page_size = sysconf(_SC_PAGESIZE);
    printf("e. Size of a page: %ld bytes\n", (page_size != -1) ? page_size : 0);

    
    if (sysinfo(&info) == 0) {
        printf("f. Total number of pages in physical memory: %ld\n", info.totalram / page_size);
        printf("g. Number of currently available pages: %ld\n", info.freeram / page_size);
    } else {
        printf("f. Total number of pages in physical memory: Not available\n");
        printf("g. Number of currently available pages: Not available\n");
    }

    return 0;
}
/*____________________________________________________________________________
 OUTPUT

 a. Maximum length of arguments to exec: 2097152 bytes
b. Maximum number of simultaneous processes per user: soft = 61672, hard = 61672
c. Number of clock ticks per second: 100
d. Maximum number of open files: soft = 1024, hard = 1048576
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 3992498
g. Number of currently available pages: 2647672
_______________________________________________________________________________
*/
