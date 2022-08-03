#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int num, sum = 0;

    num = 8;
    printf("We have %d elements to allocate memory to\n", num);

    // ptr = (cast-type*) calloc(number of elements, byte-size of each element)

    ptr = (int *)calloc(num, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    printf("Memory allocation has been successful using calloc\n");

    free(ptr);

    printf("Calloc or contiguous memory has been freed or de-allocated\n");
}