#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // when user hits enter, then the program will lock the file
    // when user hits enter again, the program will unlock the file
    struct flock flk = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int fd; // file descriptor
    flk.l_pid = getpid();

    if (argc > 1)
        flk.l_type = F_RDLCK;

    if ((fd = open("24_FileLocking_Notes.md", O_RDWR)) == -1) {
        perror("Error in opening file");
        exit(1);
    }

    printf("Hit Enter to lock the file \n");
    getchar();

    printf("Checking if we can lock the file or not \n");

    if (fcntl(fd, F_SETLKW, &flk) == -1) {
        // F_SETLKW is the argument which tells the fcntl function
        // to attempt to obtain the lock requested in the structure flk
        // if the lock cannot be obtained since someone else has the lock already, then fcntl() function will wait
        // until the lock has cleared, then will set it itself
        perror("fcntl error");
        exit(1);
    }
    printf("We have locked it succesfully! \n");
    printf("Hit Enter to unlock the file \n");
    getchar();

    flk.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &flk) == -1) {
        // F_SETLK is almost identical to F_SETLKW except that
        // it will not wait if it cannot return a lock
        // it will return immediately
        perror("fcntl error");
        exit(1);
    }

    printf("Yes, file has been unlocked \n");

    close(fd);
}