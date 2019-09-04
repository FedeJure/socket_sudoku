#ifndef _SERVER_E
#define _SERVER_E
#include "socket.h"


int start_server(char* service);
int command_receive(socket_t* socket);

#endif