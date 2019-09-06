#include "client.h"
#include "socket.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define COMMAND_LENGTH 30

int start_client(char* address, char* service) {
    socket_t socket;
    if (socket_init(&socket) == -1) {
        perror("Error initializing socket.\n");
        return -1;
    }

    if (socket_connect(&socket, address, service)) {
        perror("Error connecting to socket.\n");
        return -1;
    }

    while (true) {
        char input_command[COMMAND_LENGTH];
        printf("[sudoku input]> ");
        int res = scanf("%s",input_command);
        if (res == -1) {
            perror("Error reading command\n");
            continue;
        }
        _proccess_command(input_command);
    }
    return 0;
}

int _proccess_command(char* command) {
    return 0;
}