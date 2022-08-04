#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char fn[] = "linux_temp.fifo";
    char out[100] = "This is FIFO and this is linux", in[100];
    int rf, wf;

    if (mkfifo(fn, S_IRWXU) != 0) {
        perror("mkfifo() error");
    } else {
        if ((rf = open(fn, O_RDONLY | O_NONBLOCK)) < 0)
            perror("open() error while on the writing end");
        else {
            if (write(wf, out, strlen(out) + 1) == -1)
                perror("write() error");
            else if (read(rf, in, strlen(in)) == -1)
                perror("read() error");
            else {
                printf("reading '%s' from FIFO\n", in);
            }
            close(wf);
        }
        close(rf);
    }
    unlink(fn);
}