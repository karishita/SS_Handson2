/*
Name : 20_writer.c
Author : Ishita Kar
Description:Program that writes to the FIFO (One way communication)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	
	int fd=open("mypipe",O_WRONLY);
	char* message="Hello from 20_writer.c. I am writing to FIFO";
	int len=strlen(message);
	write(fd,&len,sizeof(len));
	if(write(fd,message,len)==len)
	printf("Write Succesful \n");
	else
	printf("Error in write \n");
	return 0;
}
/*_______________________________________________________________________________
 OUTPUT

 Write Succesful
 ________________________________________________________________________________
*/

