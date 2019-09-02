#include "socket.h"
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int socket_init(socket_t* self) {
    self->fd = socket(AF_INET, SOCK_STREAM, 0);
    return 0;
}

int socket_release(socket_t* self) {
    close(self->fd);
    return 0;
}

int socket_connect(socket_t* self, char* address, char* service) {
    struct sockaddr_in ip4addr;
    ip4addr.sin_family = AF_INET;
    ip4addr.sin_port = htons(80);
    inet_pton(AF_INET, address, &ip4addr.sin_addr);
    int res = connect(self->fd,(struct sockaddr*)&ip4addr, sizeof(ip4addr));

    if (res) {
        perror("Error trying connect\n");
    }

    return 0;
}

int socket_listen(socket_t self, char* service) {
    
    return 0;
}