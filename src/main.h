typedef struct {
    char* client_command;
    char* server_command;
    int client_count_command;
    int server_count_command;

} args_t;

int _check_params(int argc, char* argv[]);