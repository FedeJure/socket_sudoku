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

#define ERROR 1
#define SUCCESS 0

int start_client(char* address, char* service) {
    socket_t socket;
    if (socket_init(&socket) == -1) {
        return ERROR;
    }

    if (socket_connect(&socket, address, service)) {
        return ERROR;
    }
    while (socket.fd != -1) {
        fflush(stdin);
        char* input_command = fgets(input_command, COMMAND_LENGTH, stdin);        
        _proccess_command(&socket, input_command);
    }
    return SUCCESS;
}

int _proccess_command(socket_t* socket, const char* buffer) {

    if (strlen(buffer) > 20) {
        return ERROR;
    }
    if (buffer[0] == ' ') {
        fprintf(stderr,"%s\n","No pueden haber espacios antes de un comando.");
        return ERROR;
    }
    char command[COMMAND_LENGTH];
    bzero(command,COMMAND_LENGTH);
    sscanf(buffer,"%s",command);
    if (strcmp(command,GET) == 0){
        return _client_proccess_get(socket, buffer);
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
    return ERROR;
}

int _client_proccess_get(socket_t* socket, const char * buffer) {
    if (strlen(buffer) > 4) {
        return ERROR;
    }
    
    if (socket_send(socket->fd, "G", 1) < 0) {
        return ERROR;
    }
    int length = socket_read_next_length(socket->fd);
    if (length < 0) { return -1; }
    
    char* received = malloc(sizeof(char)*length);
    if (socket_read(socket->fd, received, length) < 0 ) {
        return ERROR;
    }
    printf("%s", received);
    free(received);
    return SUCCESS;
}

int _client_proccess_put(socket_t* socket, const char* buffer) {
    int value;
    int row;
    int column;
    sscanf(buffer, "put %d in %d,%d\n", &value, &row, &column);
    if ((value < 1 || value > 9)) {
        fprintf(stderr,"%s\n","​Error en el valor ingresado. Rango soportado: [1,9]");
        return ERROR;
    }
    if ((row < 1 || row > 9) || (column < 1 || column > 9)) {
        fprintf(stderr,"%s\n","Error en los índices. Rango soportado: [1,9]");
        return ERROR;
    }
    if (socket_send(socket->fd, "P", 1) < 0) {
        return ERROR;
    }
    char to_send[] = {row, column, value };
    if (socket_send(socket->fd, to_send, 3) < 0) {
        return ERROR;
    }

    int length = socket_read_next_length(socket->fd);
    if (length < 0) { return ERROR; }
    
    char* received = malloc(sizeof(char)*length);
    if (socket_read(socket->fd, received, length) < 0) {
        return ERROR;
    }
    printf("%s", received);
    return SUCCESS;
}


int _client_proccess_verify(socket_t* socket, const char* buffer) {

    if (strlen(buffer) > 7) {
        return ERROR;
    }
    if (socket_send(socket->fd, "V", 1) < 0) {
        return ERROR;
    }

    int length = socket_read_next_length(socket->fd);
    if (length < 0) { return ERROR; }
    
    char* received = malloc(sizeof(char)*length);
    if (socket_read(socket->fd, received, length) < 0) {
        return ERROR;
    }

    printf("%s", received);

    return SUCCESS;
}


int _client_proccess_reset(socket_t* socket, const char* buffer) {
    if (strlen(buffer) > 6) {
        return ERROR;
    } 
    if (socket_send(socket->fd, "R", 1) < 0) {
        return ERROR;
    }
    int length = socket_read_next_length(socket->fd);
    if (length < 0) { return ERROR; }
    char* received = malloc(sizeof(char)*length);
    if (socket_read(socket->fd, received, length) < 0) {
        return ERROR;
    }
    printf("%s", received);
    return SUCCESS;
}



int _client_proccess_exit(socket_t* socket, const char* buffer) {
    socket_release(socket);
    return SUCCESS;
}
