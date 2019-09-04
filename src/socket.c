#include "socket.h"
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <assert.h>
#include <stdbool.h>

#define ALLOWED_CONNECTIONS 1
#define BUFFER_SIZE 30

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
    ip4addr.sin_port = htons(atoi(service));
    inet_pton(AF_INET, address, &ip4addr.sin_addr);
    int res = connect(self->fd,(struct sockaddr*)&ip4addr, sizeof(ip4addr));

    if (res == -1) {
        perror("Error trying connect\n");
    }

    return 0;
}

int socket_listen(socket_t* self, const char* service, char* buffer, size_t size) {
    struct sockaddr_in ip4addr;
    ip4addr.sin_family = AF_INET; 
    ip4addr.sin_addr.s_addr = INADDR_ANY; 
    ip4addr.sin_port = htons( atoi(service) ); 
    
    int binded = bind(self->fd, (const struct sockaddr*)&ip4addr,sizeof(ip4addr));
    if (binded == -1) {
        perror("Error getting name for socket\n");
        return -1;
    }
    
    int listened = listen(self->fd, ALLOWED_CONNECTIONS);
    if (listened < 0) {
        perror("Error trying listen.\n");
        return -1;
    }


    size_t socket_size = sizeof(ip4addr);
    int accepted = accept(self->fd, (struct sockaddr*) &ip4addr, (socklen_t*)&socket_size);
    if (accepted < -1) {
        perror("Error accepting incomming connection\n");
        return -1;
    }
    _socket_read(accepted, buffer, size);
    return 0;
}

int _socket_read(int client_fd, char* buffer, size_t size) {

    int readed_size = 0;
    while(readed_size < size) {
        int res = recv(client_fd,&buffer[readed_size], size, MSG_NOSIGNAL);
        if (res < 0) {
            perror("Error receiving data\n");
        }
        readed_size += res;

    }
    return 0;
}