/*GOAL: Write a C program to generate Collatz conjecture in a child process*/

/*
The Collatz conjecture states for any positive integer n,
   n = n/2, if n is even
   n = 3n + 1, if n is odd
*/
// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {
    // intialize number user will input
    int n = atoi(argv[1]);
    
    // create a child process
    pid_t pid = fork();
    // use wait to let child finish executing
    wait(NULL);

    // if the fork fails, print an error message
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    // what to do for the child process
    else if (pid == 0) {
        printf("Child process\n");
        // have child process print the Collatz conjecture
        while (n != 1) {
            printf("%d ", n);
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
        }
        printf("%d\n", n);
    }
    // what to do fo parent process
    else {
        printf("Parent process\n");
    }
    return 0;
}
