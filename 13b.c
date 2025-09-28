/*
Name : 13b.c
Author : Ishita Kar
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/
//Sender program

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);  // convert string to integer

    if (kill(pid, SIGSTOP) == -1) {
        printf("Failed to send SIGSTOP to process %d\n", pid);
        return 1;
    }

    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}

/*_____________________________________________________________________________
 OUTPUT

ishita@ishita-lin:~/handson_2$ ./13b 5118
Sent SIGSTOP to process 5118
_______________________________________________________________________________
*/
