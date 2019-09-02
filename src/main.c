#include "main.h"
#include "sudoku/sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]) {
    printf("Starting program...\n");
    _check_params(argc, argv);
    return 0;
}

int _check_params(int argc, char* argv[]) {

    char* CLIENT_COMMAND = "client";
    char* SERVER_COMMAND = "server";
    int CLIENT_COUNT_COMMANDS = 3;
    int SERVER_COUNT_COMMANDS = 2;
    
    int count_commands = argc - 1;

    int response = 0;
    char* error_message = "";

    
    if (count_commands < SERVER_COUNT_COMMANDS || count_commands > CLIENT_COUNT_COMMANDS) {
        response = -1;
        perror("Invalid number of argument passed\n");
    }

    if (strcmp(argv[1],CLIENT_COMMAND) == 0 && count_commands != CLIENT_COUNT_COMMANDS) {
        response = -1;
        perror("Invalid number of argument for 'client' command\n");
    }

    if (strcmp(argv[1],SERVER_COMMAND) == 0 && count_commands != SERVER_COUNT_COMMANDS) {
        response = -1;
        perror("Invalid number of argument for 'server' command\n");        
    }

    return response;
}