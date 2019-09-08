#include "client.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#define COMMAND_LENGTH 30

#define GET "get"
#define PUT "put"
#define VERIFY "verify"
#define RESET "reset"
#define EXIT "exit"

int start_client(char* address, char* service) {
    socket_t socket;
    int connected = 1;
    if (socket_init(&socket) == -1) {
        perror("Error initializing socket.\n");
        return -1;
    }

    if (socket_connect(&socket, address, service)) {
        perror("Error connecting to socket.\n");
        return -1;
    }

    while (connected == 1) {
        char* input_command;
        printf("[sudoku input]> ");
        fflush(stdin);
        input_command = fgets(input_command, COMMAND_LENGTH, stdin);
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
    bzero(command,10);

    sscanf(buffer,"%s",command);
    if (strcmp(command,GET) == 0){
        return _client_proccess_get(socket,buffer);
    }

    if (strcmp(command,PUT) == 0) {
        return _client_proccess_put(socket, buffer);
    }

    if (strcmp(command,VERIFY) == 0) {
        return _client_proccess_verify(socket, buffer);
    }

    if (strcmp(command,RESET) == 0) {
        return _client_proccess_reset(socket, buffer);
    }

    if (strcmp(command,EXIT) == 0) {
        return _client_proccess_exit(socket, buffer);
    }
    return 0;
}

int _client_proccess_get(socket_t* socket, const char * buffer) {
    int res;
    uint32_t length = 0;
    uint32_t network_length = 0;
    if (strlen(buffer) > 4) {
        printf("command 'get' no accept params.\n");
        return -1;
    }
    res = socket_send(socket, "G", 1);
    if (res < 0) { return -1; }
    char* length_read = malloc(sizeof(char));
    bzero(length_read,1);
    res = socket_read(socket->fd, length_read, 1);
    printf("readed %d %s\n",res,length_read);
    if (res < 0) { return -1; }
    network_length = length_read[0];
    length = ntohl(network_length);
    char* received = malloc(sizeof(char)*length);
    res = socket_read(socket->fd, received, length);
    printf("%s\n",received);
    if (res < 0) { return -1; }
    free(received);
    return res;
}

int _client_proccess_put(socket_t* socket, const char* buffer) {
        int value;
        int row;
        int column;
        sscanf(buffer, "put %d in %d,%d\n", &value, &row, &column);
        printf("%d %d %d\n",value, row, column);
        if ((value < 1 || value > 9)) {
            printf("​Error en el valor ingresado. Rango soportado: [1,9]\n");
            return -1;
        }
        if ((row < 1 || row > 9) || (column < 1 || column > 9)) {
            printf("Error en los índices. Rango soportado: [1,9]\n");
            return -1;
        }
    return 0;
}


int _client_proccess_verify(socket_t* socket, const char* buffer) {

    if (strlen(buffer) > 7) {
        printf("command 'verify' no accept params.\n");
        return -1;
    }
    return 0;
}


int _client_proccess_reset(socket_t* socket, const char* buffer) {
    if (strlen(buffer) > 6) {
        printf("command 'reset' no accept params.\n");
        return -1;
    } 
    return 0;
}



int _client_proccess_exit(socket_t* socket, const char* buffer) {
    exit(0);
    return 0;
}