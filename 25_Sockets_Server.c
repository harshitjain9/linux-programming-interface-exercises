#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int serv_fd, n_socket, v_read;
    struct sockaddr_in address;

    int opt = 1;
    int addr_length = sizeof(address);
    char buffer[1024] = {0};

    char *hey = "Hey I am server!";

    // AF_INET refers to IPv4
    // SOCK_STREAM refers to TCP
    if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // socket has failed
        perror("Socket failure");
        exit(1);
    }

    if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // now will attach socket to the port 8080 using bind function
    if (bind(serv_fd, (struct sockaddr *)&address, sizeof(address)) == 0) {
        perror("bind failure");
        exit(1);
    }

    // puts the server in a passive mode and waits for the client to approach the server
    if (listen(serv_fd, 3) < 0) {
        perror("listen error");
        exit(0);
    }

    // accept extracts the first connection request on the queue of pending connections for the listening request
    // creates a new connected socket and returns a new file descriptor referring to that socket
    // connection established b/w client and server and they ar ready to transfer data
    if ((n_socket = accept(serv_fd, (struct sockaddr *)&address, (socklen_t *)&addr_length)) < 0) {
        perror("Accept error");
        exit(1);
    }

    v_read = read(n_socket, buffer, 1024);
    printf("%s\n", buffer);

    // now send the request
    send(n_socket, hey, strlen(hey), 0);
    printf("Hey message sent! \n");
}