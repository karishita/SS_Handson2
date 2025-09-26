/*
Name : 20_reader.c
Author : Ishita Kar
Description:Program that reads from  the FIFO (One way communication)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{

        int fd=open("mypipe",O_RDONLY);
	int len;
	read(fd,&len,sizeof(len));
	char buf[len+1];
        read(fd,buf,len);
	buf[len]='\0';
	printf("The message is %s ",buf);

}

/*_________________________________________________________________________________
 OUTPUT
 
 The message is Hello from 20_writer.c. I am writing to FIFO 
__________________________________________________________________________________
 */

