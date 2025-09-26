/*
Name : 17b.c
Author : Ishita Kar
Description:program to execute ls -l | wc using dup2
Date: 11th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
        int fd[2];
        pipe(fd);
        if(!fork())
        {
                close(1);
                dup2(fd[1],1);
                close(fd[0]);
                execlp("ls","ls",NULL);
        }
        else
        {
                close(0);
                dup2(fd[0],0);
                close(fd[1]);
                execlp("wc","wc",NULL);
        }
}

/*_____________________________________________________________________________
 OUTPUT

 11      10      73
_______________________________________________________________________________

