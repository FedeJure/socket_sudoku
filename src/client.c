#include "client.h"
#include "socket/socket.h"

int start_client(char* address, char* service) {
    socket_t socket;
    socket_init(&socket);
    socket_connect(&socket, address, service);
}