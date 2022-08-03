#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char new_file[] = "/Users/harshit/Desktop/NewFolder/new.txt";
    char new_dir[] = "/Users/harshit/Desktop/NewFolder";

    // unlink the file
    unlink(new_file);

    if (rmdir(new_dir) != 0) {
        perror("rmdir error");
    } else {
        puts("removed!");
    }
}