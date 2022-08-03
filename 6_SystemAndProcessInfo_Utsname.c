#include <errno.h> //for error
#include <stdio.h>
#include <stdlib.h> //standard library
#include <sys/utsname.h>

int main() {
    struct utsname buff;

    errno = 0;
    if (uname(&buff) != 0) { // uname function returns sys info in buff
        perror("uname doesn't return 0, so there's an error");
        exit(EXIT_FAILURE);
    }

    printf("System Name = %s\n", buff.sysname); // os name (eg. "Linux")
    printf("Node Name = %s\n", buff.nodename);  // name within "some implementation-defined network"
    printf("Release = %s\n", buff.release);     // os release (eg. "2.6.28")
    printf("Version = %s\n", buff.version);     // os version
    printf("Machine = %s\n", buff.machine);     // hardware identifier (eg. x86_64)
}