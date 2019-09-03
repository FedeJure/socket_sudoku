#include "main.h"
#include "sudoku/sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "server.h"

int main (int argc, char* argv[]) {

    args_t args = {
        "client",
        "server",
        3,
        2,
    };

    _check_params(argc, argv, &args);

    char* address;
    char* service;

    _extract_params(argc, argv, &address, &service, &args);
    int is_server = (strcmp(args.server_command, argv[1]) == 0);
    return is_server ? _start_server(service) : _start_client(address, service);
}

int _check_params(int argc, char* argv[], args_t* args) {
    int count_commands = argc - 1;

    int response = 0;
    char* error_message = "";

    
    if (count_commands < args->server_count_command || count_commands > args->client_count_command) {
        response = -1;
        perror("Invalid arguments passed\n");
    }

    if (count_commands > 0 && strcmp(argv[1],args->client_command) == 0 && count_commands != args->client_count_command) {
        response = -1;
        perror("Invalid number of argument for 'client' command\n");
    }

    if (count_commands > 0 && strcmp(argv[1],args->server_command) == 0 && count_commands != args->server_count_command) {
        response = -1;
        perror("Invalid number of argument for 'server' command\n");        
    }

    if (response == -1) exit(0);

    return response;
}

int _extract_params(int argc,char* argv[], char** address, char** service, args_t* args) {
    if (strcmp(argv[1],args->client_command) == 0) {
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
}