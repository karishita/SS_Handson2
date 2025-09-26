/*
Name : 16.c
Author : Ishita Kar
Description:program to send and receive data from parent to child vice versa. Use twoway communication.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
        int fd1[2];
	int fd2[2];
        char buf1[30];
	char buf2[30];
        pipe(fd1);
	pipe(fd2);
	//child 
        if(!fork())
        {
                close(fd1[1]);
		close(fd2[0]);
		write(fd2[1],"Hello from child\n",18);
                read(fd1[0],buf1,18);
                printf("The message from parent: %s\n",buf1);
        }
	//parent
        else
        {
              close(fd1[0]);
	      close(fd2[1]);
              write(fd1[1],"Hello from parent\n",18);
	      read(fd2[0],buf2,18);
	      printf("The message from child: %s\n",buf2);
        }
        return 0;
}

/*_________________________________________________________________________________
 OUTPUT

 The message from parent: Hello from parent

The message from child: Hello from child
____________________________________________________________________________________
*/

