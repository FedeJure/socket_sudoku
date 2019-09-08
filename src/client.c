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
        fflush(stdin);
        input_command = fgets(input_command, COMMAND_LENGTH, stdin);
        fflush(stdin);
        _proccess_command(&socket, input_command);
    }
    return 0;
}

int _proccess_command(socket_t* socket, const char* buffer) {
    if (strlen(buffer) > 20) {
        return -1;
    }
    if (buffer[0] == ' ') {
        printf("No pueden haber espacios antes de un comando.\n");
        return -1;
    }
    char command[10];

    sscanf(buffer,"%s",command);
    if (strcmp(command,GET) == 0){
        if (strlen(buffer) > 4) {
            printf("command 'get' no accept params.\n");
            return -1;
        }
        int res = socket_send(socket, buffer, 3);
        return res;
    }

    if (strcmp(command,PUT) == 0){
        if (strlen(buffer) > 13) {
            printf("command 'put' no accept params.\n");
            return -1;
        }
        int value;
        int row;
        int column;
        sscanf(buffer, "put %d in %d,%d\n", &value, &row, &column);
        printf("%d %d %d\n",value, row, column);
        if (value < 1 || value > 9) {
            printf("El valor ingresado debe estar entre 1 y 9\n");
            return -1;
        }
        if (row < 1 || row > 9) {
            printf("El valor ingresado debe estar entre 1 y 9\n");
            return -1;
        }
        if (column < 1 || column > 9) {
            printf("El valor ingresado debe estar entre 1 y 9\n");
            return -1;
        }


    }

    if (strcmp(command,VERIFY) == 0){
        if (strlen(buffer) > 7) {
            printf("command 'verify' no accept params.\n");
            return -1;
        }
    }

    if (strcmp(command,RESET) == 0){
        if (strlen(buffer) > 6) {
            printf("command 'reset' no accept params.\n");
            return -1;
        } 
    }

    if (strcmp(command,EXIT) == 0){
        exit(0);
    }
    return 0;
}