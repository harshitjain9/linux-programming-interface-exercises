#include <pthread.h> // for thread-related functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *ThreadFunction(void *vargp) {
    sleep(2);
    printf("Hello Threading!\n");
    return NULL;
}

int main() {
    pthread_t thread_id; // an integer used to identify thread in the system
    printf("Before using threading\n");
    pthread_create(&thread_id, NULL, ThreadFunction, NULL); // creates a thread which executes ThreadFunction
    pthread_join(thread_id, NULL);                          // blocking statement, waits for created thread to terminate (similar to wait for processes)
    printf("After using threading\n");
    exit(0);
}
