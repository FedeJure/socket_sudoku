#ifndef _SOCKET_E
#define _SOCKET_E
#include <stdlib.h>


typedef struct socket {
    int fd;
    char* service;
} socket_t;

int socket_init(socket_t* self);
int socket_release(socket_t* self);
int socket_connect(socket_t* self, char* address, char* service);
int socket_listen(socket_t* self, char* service);  
int socket_read(int client_fd, char* buffer, int size);
int socket_accept(socket_t* self, int* client_fd, char* service);
int socket_send(socket_t* self, const char* buffer, int length);

#endif