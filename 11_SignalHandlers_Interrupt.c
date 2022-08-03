#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sighandler(int);

int main() {
    signal(SIGINT, sighandler); // whenever you press Ctrl+C (or interrupt the program), the function sighandler will be executed
    for (;;) {
        printf("Sleeping...\n");
        sleep(3);
    }
}

void sighandler(int signum) {
    printf("Caught Signal %d, and now I am exiting..\n", signum);
    exit(1);
}