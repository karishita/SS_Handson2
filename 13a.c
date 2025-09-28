/*
Name : 13a.c
Author : Ishita Kar
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

//reciever program


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
    fflush(stdout);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    
    if (sigaction(SIGSTOP, &sa, NULL) == -1) {
        perror("sigaction");
    }

    printf("Receiver running with PID=%d\n", getpid());
    fflush(stdout);

    while (1) {
        printf("Waiting...\n");
        fflush(stdout);
        sleep(2);
    }
    return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Receiver running with PID=5118
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...


[1]+  Stopped                 ./13a
________________________________________________________________________________*/
