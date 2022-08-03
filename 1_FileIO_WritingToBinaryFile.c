#include <stdio.h>
#include <stdlib.h>

struct threeNums {
    int num1, num2, num3;
};

int main() {
    int num;
    struct threeNums number;

    FILE *fptr;

    if ((fptr = fopen("program.bin", "wb")) == NULL) {
        printf("ERROR opening file");
        exit(1);
    }
    for (num = 1; num < 5; num++) {
        number.num1 = num;
        number.num2 = 2 * num;
        number.num3 = 2 * num + 3;

        fwrite(&number, sizeof(struct threeNums), 1, fptr);
    }

    fclose(fptr);
}