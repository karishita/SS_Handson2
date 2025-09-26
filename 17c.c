/*
Name : 17c.c
Author : Ishita Kar
Description:program to execute ls -l | wc using fcntl
Date: 11th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
        int fd[2];
        pipe(fd);
        if(!fork())
        {
                close(1);
                fcntl(fd[1],F_DUPFD,1);
                close(fd[0]);
                execlp("ls","ls",NULL);
        }
        else
        {
                close(0);
                fcntl(fd[0],F_DUPFD,0);
                close(fd[1]);
                execlp("wc","wc",NULL);
        }
}

/*_____________________________________________________________________________
 OUTPUT
 12      11      79
______________________________________________________________________________
*/


