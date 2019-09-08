#include "server.h"
#include <stdbool.h>
#include <stdio.h>
#include "sudoku.h"
#include <string.h>


#define COMMAND_LENGTH 30
 
int start_server(char* service) {
    sudoku_t sudoku;
    sudoku_init(&sudoku);
    // int buffer[81];
    // sudoku_draw(&sudoku,(char*)buffer);
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
    char* buffer = {0};
    char* response = {0};
    while (true) {
        if (socket_accept(socket, &client_fd, socket->service) == -1) {
            perror("Error accepting inncresomming connection\n");
            return -1;
        }

        printf("Nuevo usuario conectado.\n");
        int res = socket_read(client_fd, buffer, 1);
        printf("Recibido: %s",buffer);
        _server_proccess_command(buffer,response);
        if (res == -1) {
            perror("Error receiving buffer.\n");
            continue;
        }
    }

    return 0;
}

int _server_proccess_command(char* command, char* response) {

    return 0;
}

int _server_build_board_to_send(sudoku_t* sudoku, int size, int*** values ) {
    sudoku_get_board(sudoku,values);
    return 0;
}