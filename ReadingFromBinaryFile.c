#include <stdio.h>
#include <stdlib.h>

struct threeNums {
    int num1, num2, num3;
};

int main() {
    int num;
    struct threeNums number;

    FILE *fptr;

    if ((fptr = fopen("program.bin", "rb")) == NULL) {
        printf("ERROR opening file");
        exit(1);
    }
    for (num = 1; num < 5; num++) {
        fread(&number, sizeof(struct threeNums), 1, fptr);
        printf("num1: %d\tnum2: %d\tnum3: %d\n", number.num1, number.num2, number.num3);
    }

    fclose(fptr);
}