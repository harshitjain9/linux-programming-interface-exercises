/*
// #include <sys/inotify.h> does not work on Mac, so commenting this entire file
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <sys/types.h>
#include <unistd.h>

#define EVENT_SIZE(sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

int main() {

    int length, i = 0;
    int fd, wd;

    char buffer[BUF_LEN];

    fd = inotify_init();

    if (fd < 0) {
        perror("inotify_init");
    }

    wd = inotify_add_watch(fd, "/Users/harshit/Desktop/NewFolder", IN_MODIFY | IN_CREATE | IN_DELETE);

    length = read(fd, buffer, BUF_LEN);

    if (length < 0) {
        perror("read");
    }

    while (i < length) {
        struct inotify_event *event = (struct inotify_event *)&buffer[i];
        if (event->mask & IN_CREATE) {
            printf("The file %s was created\n", event->name);
        }
        if (event->mask & IN_DELETE) {
            printf("The file %s was deleted\n", event->name);
        }
        if (event->mask & IN_MODIFY) {
            printf("The file %s was modified\n", event->name);
        }
        i += EVENT_SIZE + event->len;
    }

    (void)inotify_rm_watch(fd, wd);
    (void)close(fd);
}
*/