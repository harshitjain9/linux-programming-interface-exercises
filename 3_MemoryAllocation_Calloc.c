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

    for (int i = 0; i < num; i++) {
        ptr[i] = i + 1;
    }

    printf("Inserted %d elements in the block as follows\n", num);

    for (int i = 0; i < num; i++) {
        printf("%d\n", ptr[i]);
    }
}