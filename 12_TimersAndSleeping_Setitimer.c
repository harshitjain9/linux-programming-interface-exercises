#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define INTERVAL 500 // number of milliseconds

void do_something(int);

int main() {
    // calling setitimer results in the os scheduling a SIGALRM to be sent to your process
    // after specified time has elapsed and once the process catches SIGALRM, what happens next
    // is described by the signal handler function, which in this case is do_something
    struct itimerval it_val;

    if (signal(SIGALRM, (void (*)(int))do_something) == SIG_ERR) {
        perror("unable to catch SIGALRM");
        exit(1);
    }

    it_val.it_value.tv_sec = INTERVAL / 1000;
    it_val.it_value.tv_usec = (INTERVAL * 1000) % 1000000;

    it_val.it_interval = it_val.it_value;

    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }

    for (;;) {
        pause();
    }
}

void do_something(int signum) {
    printf("timer went off\n");
}