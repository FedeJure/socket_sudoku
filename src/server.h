#ifndef _SERVER_E
#define _SERVER_E
#include "socket.h"


int start_server(char* service);
int command_receive(socket_t* socket);
int _server_proccess_command(char* command, char* response);

#endif