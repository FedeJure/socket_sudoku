typedef struct {
    char* client_command;
    char* server_command;
    int client_count_command;
    int server_count_command;

} args_t;

int _check_params(int argc, char* argv[], args_t* args);
int _extract_params(int argc,char* argv[], char** address, char** service, args_t* args);
int _start_server(char* service);
int _start_client(char* address, char* service);