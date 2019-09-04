#include "main.h"
#include "sudoku/sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "server.h"

#define CLIENT_COMMAND "client"
#define SERVER_COMMAND "server"
#define CLIENT_COMMAND_COUNT 3
#define SERVER_COMMAND_COUNT 2

int main (int argc, char* argv[]) {

    _check_params(argc, argv);

    char* address;
    char* service;

    _extract_params(argc, argv, &address, &service);
    int is_server = (strcmp(SERVER_COMMAND, argv[1]) == 0);
    return is_server ? _start_server(service) : _start_client(address, service);
}

int _check_params(int argc, char* argv[]) {
    int count_commands = argc - 1;

    int response = 0;
    char* error_message = "";

    
    if (count_commands < SERVER_COMMAND_COUNT || count_commands > CLIENT_COMMAND_COUNT) {
        response = -1;
        perror("Invalid arguments passed\n");
    }

    if (count_commands > 0 && strcmp(argv[1], CLIENT_COMMAND) == 0 && count_commands != CLIENT_COMMAND_COUNT) {
        response = -1;
        perror("Invalid number of argument for 'client' command\n");
    }

    if (count_commands > 0 && strcmp(argv[1], SERVER_COMMAND) == 0 && count_commands != SERVER_COMMAND_COUNT) {
        response = -1;
        perror("Invalid number of argument for 'server' command\n");        
    }

    if (response == -1) exit(0);

    return response;
}

int _extract_params(int argc,char* argv[], char** address, char** service) {
    if (strcmp(argv[1],CLIENT_COMMAND) == 0) {
        *address = argv[2];
        *service = argv[3];
    }
    else {
        *service = argv[2];
    }
    
    return 0;
}

int _start_server(char* service) {
    printf("Starting server...\n");
    return start_server(service);
}
int _start_client(char* address, char* service) {
    printf("starting client...\n");
    return start_client(address, service);
}