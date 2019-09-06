#ifndef _CLIENT_E
#define _CLIENT_E
#include "socket.h"

int start_client(char* address, char* service);
int _proccess_command(socket_t* socket, const char* command);

#endif