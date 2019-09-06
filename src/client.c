#include "client.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define COMMAND_LENGTH 30

#define GET "get"
#define PUT "put"
#define VERIFY "verify"
#define RESET "reset"
#define EXIT "exit"

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
        char* input_command;
        printf("[sudoku input]> ");
        // int res = scanf("%s 1 in 1,2",input_command);
        input_command = fgets(input_command, COMMAND_LENGTH, stdin);
        fflush(stdin);
        _proccess_command(&socket, input_command);
    }
    return 0;
}

int _proccess_command(socket_t* socket, const char* buffer) {
    if (buffer[0] == ' ') {
        printf("No pueden haber espacios antes de un comando.\n");
        return -1;
    }
    char command[10];

    sscanf(buffer,"%s",command);

    if (strcmp(command,GET) == 0){
        if (strlen(buffer) > 4) {
            printf("command 'get' no accept params.");
            return -1;
        }
        int res = socket_send(socket, buffer, 3);
        return res;
    }

    if (strcmp(command,PUT) == 0){
        
    }

    if (strcmp(command,VERIFY) == 0){
        
    }

    if (strcmp(command,RESET) == 0){
        
    }

    if (strcmp(command,EXIT) == 0){
        exit(0);
    }
    return 0;
}