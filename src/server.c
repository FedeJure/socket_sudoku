#include "server.h"
#include "socket/socket.h"

int start_server(char* service) {
    socket_t socket;
    socket_init(&socket);
    socket_listen(&socket, service);
}