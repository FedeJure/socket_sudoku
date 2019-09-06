#include "server.h"
#include <stdbool.h>
#include <stdio.h>
#include "sudoku.h"


#define COMMAND_LENGTH 30
 
int start_server(char* service) {
    sudoku_t sudoku;
    sudoku_init(&sudoku);
    socket_t socket;
    if (socket_init(&socket) == -1) {
        perror("Error initializing socket.\n");
        return -1;
    }
    if (socket_listen(&socket, service) == -1) {
        perror("Error listening with socket.\n");
        return -1;
    }
    if (command_receive(&socket) == -1) {
        perror("Error reading commands.\n");
        return -1;
    }

    return 0;
}

int command_receive(socket_t* socket) {
    int client_fd;
    while (true) {

        if (socket_accept(socket, &client_fd, socket->service) == -1) {
            perror("Error accepting inncomming connection\n");
            return -1;
        }
        char* command = '\0';
        socket_read(client_fd, command, COMMAND_LENGTH);
    }
    return 0;
}