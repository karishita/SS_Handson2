/*
Name : 21_b.c
Author : Ishita Kar
Description:Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/select.h>
int main()
{
printf("Waiting for input to FIFO for 10 seconds....\n");
int fd=open("mypipe",O_RDONLY | O_NONBLOCK);
 fd_set readfds;
 struct timeval tv;
 int ret;
 FD_ZERO(&readfds);
 FD_SET(fd,&readfds);
 tv.tv_sec=10;
 tv.tv_usec=0;
 ret=select(fd+1,&readfds,NULL,NULL,&tv);
 

 if(ret==0)
	 printf("Timeout occured\n");
 else if(ret==-1)
	 printf("Error \n");
 else
 {
	 if(FD_ISSET(fd,&readfds))
	 {
         int len;
        read(fd,&len,sizeof(len));
        char buf[len+1];
        read(fd,buf,len);
        buf[len]='\0';
        printf("The message is:  %s ",buf);
	 }
 }
}
 
/*______________________________________________________________________________
 OUTPUT

Waiting for input to FIFO for 10 seconds....
Timeout occured

ishita@ishita-lin:~/handson_2$ ./writer
Write Succesful

Waiting for input to FIFO for 10 seconds....
The message is:  Hello from 20_writer.c. I am writing to FIFO
_______________________________________________________________________________
*/

