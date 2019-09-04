#include "server.h"
#include "socket.h"

int start_server(char* service) {
    socket_t socket;
    socket_init(&socket);

    /*
    Esto en alguna funcion para leer comandos
    */
    char* command = "";
    size_t size = 32;
    socket_listen(&socket, service, command, size);
    return 0;
}