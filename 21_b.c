/*
Name : 21_b.c
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
        

	//write
        char* message="Hello from 20_b.c. I am writing to FIFO";
        int len2=strlen(message);
        write(fd1,&len2,sizeof(len2));
        if(write(fd1,message,len2)==len2)
        printf("Write Succesful \n");
else
        printf("Error in write \n");

        //Read
        int len1;
        read(fd2,&len1,sizeof(len1));
        char buf[len1+1];
        read(fd2,buf,len1);
        buf[len1]='\0';
        printf("The message is %s ",buf);
}
/*____________________________________________________________________________
OUTPUT

  Write Succesful 
The message is Hello from 20_a.c. I am writing to FIFO
_________________________________________________________________________-___
*/
