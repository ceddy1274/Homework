/*GOAL: Create a C program that forks a child process and ultimately becomes a zombie process (zombie must stay for at least 10 seconds)*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // fork to create a child process
    pid_t pid = fork();
    // wait for child to finish executing
    wait(NULL);

    // if there was an error in fork print message and exit
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    // code for the child process
    else if (pid == 0) {
        printf("Child start\n");
        // go to sleep so child can become a zombie
        sleep(10);
        printf("Child done\n");
    }
    // code for the parent process 
    else {
        printf("Parent\n");
    }
    return 0;
}

