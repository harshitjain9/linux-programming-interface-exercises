#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    char *args[] = {"./simple", NULL};
    execvp(args[0], args);
    // this entire process will be replaced by ./simple
    // any statements below will not be executed

    printf("This statement will not be executed\n");
}