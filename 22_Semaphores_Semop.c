#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h> // for semaphores related stuff
#include <sys/types.h>
#include <unistd.h>

#define KEY 0x1111

// semwait
struct sembuf a = {0, -1, SEM_UNDO}; // SEM_UNDO allows a process's termination to undo operations on semaphore.
// Helpful when a process terminates acidentally leaving other processes to be blocked indefinitely waiting for the
// semaphore's value to be changed by the terminated process

// semsignal
struct sembuf b = {0, +1, SEM_UNDO};

int main() {
    int id = semget(KEY, 1, 0666 | IPC_CREAT); // get id of IPC semaphore
    if (id < 0) {
        perror("semget error");
        exit(1);
    }

    union semun su;
    su.val = 1;

    if (semctl(id, 0, SETVAL, su) < 0) {
        perror("semctl error");
        exit(1);
    }

    int pid;
    pid = fork();
    srand(pid);

    if (pid < 0) {
        perror("fork error");
        exit(1);
    } else {
        char *se = "abc";
        int l = strlen(se);

        for (int i = 0; i < l; i++) {
            if (semop(id, &a, 1) < 0) {
                perror("semop error with a");
                exit(1);
            }
            putchar(se[i]);
            fflush(stdout);
            sleep(1);
            putchar(se[i]);
            fflush(stdout);

            if (semop(id, &b, 1) < 0) {
                perror("semop error with b");
                exit(1);
            }

            sleep(1);
        }
    }
}