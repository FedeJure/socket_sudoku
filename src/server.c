#include "server.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <strings.h>


#define PUT_LENGTH 12
#define GET "G"
#define PUT "P"
#define VERIFY "V"
#define RESET "R"
 
int start_server(char* service) {
    sudoku_t sudoku;
    sudoku_init(&sudoku);
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
    int client_fd;
    char buffer[1];
    bzero(buffer,1);
    if (socket_accept(self->socket, &client_fd, self->socket->service) == -1) {
        return -1;
    }

    while (true) {
        if (socket_read(client_fd, buffer, 1) < 1) {
            continue;
        }
        
        if (_server_proccess_command(self, client_fd, buffer) < 1) {
            // perror("Error receiving buffer.\n");
            continue;
        }

    }

    return 0;
}

int _server_proccess_command(server_t* self, int client_fd, const char* command) {
    if (strcmp(command, GET) == 0) {
        return _server_proccess_get_command(self, client_fd, command);
    }
    else if (strcmp(command,PUT) == 0) {
        return _server_proccess_put_command(self, client_fd, command);
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

int _server_proccess_get_command(server_t* self, int client_fd, const char* command) {
    char* board = malloc(sizeof(char)*1000);
    bzero(board,sizeof(char)*1000);
    sudoku_draw(self->sudoku,board);
    int length = strlen(board);

    if ( socket_send_next_length(client_fd, length) < 0) {
        return -1;
    }
    if ( socket_send(client_fd,board,length) < 0) {
        return -1;
    }

    free(board);
    return 0;
}

int _server_proccess_put_command(server_t* self, int client_fd, const char* command) {

    char* input = malloc(sizeof(char)*(PUT_LENGTH+1));
    if (socket_read(client_fd, input, 3) < 0) {
        return -1;
    };
    printf("%s", input);
    return 0;
}