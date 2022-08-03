#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t cpid; // pid_t comes from sys/wait.h

    if (fork() == 0) {
        exit(0); // terminate the child process
    } else {
        cpid = wait(NULL);
    }

    printf("Parent process id (pid) : %d\n", getpid());
    printf("Child process id (pid) : %d\n", cpid);
}