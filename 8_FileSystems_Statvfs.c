#include <stdio.h>
#include <sys/statvfs.h>

// statvfs uses pathname to speecify name of any file in the file system
// fstatvfs uses open file descriptor referring to any file in the file system
int main() {
    struct statvfs buf;

    if (statvfs(".", &buf) == -1) {
        perror("error");
        exit(1);
    }

    printf("each block has a size of %ld bytes\n", buf.f_frsize); // f_frzie = fundamental file system block size in bytes

    printf("there are %ld blocks available out of %ld\n", buf.f_bavail, buf.f_blocks);
}