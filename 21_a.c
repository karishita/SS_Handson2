/*
Name : 21_a.c
Author : Ishita Kar
Description:Program for two processes communicating with using FIFO(2 way communication)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{

	int fd1=open("mypipe1",O_RDWR);
	int fd2=open("mypipe2",O_RDWR);

	//Read
	int len1;
        read(fd1,&len1,sizeof(len1));
        char buf[len1+1];
        read(fd1,buf,len1);
        buf[len1]='\0';
        printf("The message is %s ",buf);

	//write
	char* message="Hello from 20_a.c. I am writing to FIFO\n";
        int len2=strlen(message);
        write(fd2,&len2,sizeof(len2));
        if(write(fd2,message,len2)==len2)
        printf("Write Succesful \n");
        else
        printf("Error in write \n");
}
/*________________________________________________________________________________
 OUTPUT

 The message is Hello from 20_b.c. I am writing to FIFO 
 Write Succesful
 ________________________________________________________________________
 */

