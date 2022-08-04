#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_txt[500];
} message;

int main() {

    key_t key;
    int msg_id;

    key = ftok("progfile", 65);
    msg_id = msgget(key, 0666 | IPC_CREAT); // msg_id refers to the identifier of the message queue associated with the key parameter.
    // it can be used to either obtain the identifier of a previously created message queue,
    // or to create a new set
    message.msg_type = 1;

    printf("Please write data to send: \n");
    fgets(message.msg_txt, 500, stdin);

    msgsnd(msg_id, &message, sizeof(message), 0); // appends a copy of message pointed to by "message" to the message queue whose identifier is specified by msg_id

    printf("We have sent: %s \n", message.msg_txt);
}