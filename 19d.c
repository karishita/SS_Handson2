/*
Name : 19d.c
Author : Ishita Kar
Description:Program to create FIFO using mkfifo library function
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	if(mkfifo("mypipe3",0777)==0)
		printf("FIFO mypipe3  created successfully\n");
	else
            printf("Error\n");
}

/*__________________________________________________________________________________
 OUTPUT
 FIFO mypipe3  created successfully

 Terminal 1:
echo "hello" > mypipe3

Terminal 2:
hello
_________________________________________________________________________________
*/
