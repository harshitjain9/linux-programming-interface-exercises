#include <stdio.h>
#include <time.h> //built in header file containing time related functions

void func_name() {
    printf("Function starts \n");
    printf("Press any key to stop function\n");
    for (;;) { // infinite for loop
        if (getchar())
            break;
    }
    printf("Function ends\n");
}
int main() {
    clock_t t;
    t = clock();
    func_name();
    t = clock() - t;

    double time_taken_by_func = ((double)t) / CLOCKS_PER_SEC;

    printf("The processing time of function is: %f\n", time_taken_by_func);
}