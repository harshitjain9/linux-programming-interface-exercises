#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int res = mkdir("/Users/harshit/Desktop/NewFolder", 0777); // assigns all permissions to NewFolder
    if (res == 0)                                              // successful
        printf("Creation of directory has been successful!\n");
    else
        printf("Creation of directory has failed!\n");
}