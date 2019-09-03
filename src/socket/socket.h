#ifndef _SOCKET_E
#define _SOCKET_E
typedef struct {
    int fd;
} socket_t;

int socket_init(socket_t* self);
int socket_release(socket_t* self);
int socket_connect(socket_t* self, char* address, char* service);
int socket_listen(socket_t* self, const char* service);
#endif