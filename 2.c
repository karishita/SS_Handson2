/*
Name : 2.c
Author : Ishita Kar
Description:Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>

void print_limit(const char* name,int resource)
{
	struct rlimit limit;
	getrlimit(resource,&limit);
	printf("%-15s Soft = %10ld  Hard = %10ld\n",
               name,
               (long)limit.rlim_cur,
               (long)limit.rlim_max);
}
int main()
{
	printf("Resource Limits for this process:\n\n");

    print_limit("CPU",        RLIMIT_CPU);
    print_limit("FSIZE",      RLIMIT_FSIZE);
    print_limit("DATA",       RLIMIT_DATA);
    print_limit("STACK",      RLIMIT_STACK);
    print_limit("CORE",       RLIMIT_CORE);
    print_limit("NOFILE",     RLIMIT_NOFILE);
    print_limit("AS",         RLIMIT_AS);         
    print_limit("NPROC",      RLIMIT_NPROC);      
    print_limit("MEMLOCK",    RLIMIT_MEMLOCK);    
    print_limit("LOCKS",      RLIMIT_LOCKS);      
#ifdef RLIMIT_SIGPENDING
    print_limit("SIGPENDING", RLIMIT_SIGPENDING); 
#endif
#ifdef RLIMIT_MSGQUEUE
    print_limit("MSGQUEUE",   RLIMIT_MSGQUEUE);  
#endif
#ifdef RLIMIT_NICE
    print_limit("NICE",       RLIMIT_NICE);       
#endif
#ifdef RLIMIT_RTPRIO
    print_limit("RTPRIO",     RLIMIT_RTPRIO);     
#endif
#ifdef RLIMIT_RTTIME
    print_limit("RTTIME",     RLIMIT_RTTIME);     
#endif

    return 0;
}


/*_____________________________________________________________________________
 Resource Limits for this process:

CPU             Soft =         -1  Hard =         -1
FSIZE           Soft =         -1  Hard =         -1
DATA            Soft =         -1  Hard =         -1
STACK           Soft =    8388608  Hard =         -1
CORE            Soft =          0  Hard =         -1
NOFILE          Soft =       1024  Hard =    1048576
AS              Soft =         -1  Hard =         -1
NPROC           Soft =      61672  Hard =      61672
MEMLOCK         Soft = 2044157952  Hard = 2044157952
LOCKS           Soft =         -1  Hard =         -1
SIGPENDING      Soft =      61672  Hard =      61672
MSGQUEUE        Soft =     819200  Hard =     819200
NICE            Soft =          0  Hard =          0
RTPRIO          Soft =          0  Hard =          0
RTTIME          Soft =         -1  Hard =         -1
______________________________________________________________________________
*/
