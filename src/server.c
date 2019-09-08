#include "server.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>


#define COMMAND_LENGTH 30
#define GET "G"
#define PUT "P"
#define VERIFY "V"
#define RESET "R"
 
int start_server(char* service) {
    sudoku_t sudoku;
    sudoku_init(&sudoku);
    // int buffer[81];
    // sudoku_draw(&sudoku,(char*)buffer);
    socket_t socket;
    server_t self;
    self.sudoku = &sudoku;
    self.socket = &socket;
    if (socket_init(&socket) == -1) {
        // perror("Error initializing socket.\n");
        return -1;
    }
    if (socket_listen(&socket, service) == -1) {
        // perror("Error listening with socket.\n");
        return -1;
    }
    if (server_command_receive(&self) == -1) {
        // perror("Error reading commands.\n");
        return -1;
    }

    return 0;
}

int server_command_receive(server_t* self) {
    int client_fd, res;
    char buffer[1];
    bzero(buffer,1);
    char* response = {0};
    while (true) {
        if (socket_accept(self->socket, &client_fd, self->socket->service) == -1) {
            // perror("Error accepting inncresomming connection\n");
            return -1;
        }

        printf("Nuevo usuario conectado.\n");
        res = socket_read(client_fd, buffer, 1);
        printf("Recibido: %s",buffer);
        _server_proccess_command(self, client_fd, buffer,response);
        if (res == -1) {
            // perror("Error receiving buffer.\n");
            continue;
        }
    }

    return 0;
}

int _server_proccess_command(server_t* self, int client_fd, const char* command, char* response) {
    int res;
    if (strcmp(command, GET) == 0) {
        res = socket_send(self->socket,"2",1);
        return res;
    }
    else if (strcmp(command,PUT) == 0) {
        res = socket_read(client_fd, response, 3);
    }
    else if (strcmp(command,RESET) == 0) {

    }
    else if (strcmp(command,VERIFY) == 0) {

    }
    return 0;
}

int _server_build_board_to_send(sudoku_t* sudoku, int size, int*** values ) {
    sudoku_get_board(sudoku,values);
    return 0;
}

