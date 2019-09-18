// Copyright [2019] <Federico Jure>
int _check_params(int argc, char* argv[]);
int _extract_params(int argc, char* argv[], char** address, char** service);
int _start_server(char* service);
int _start_client(char* address, char* service);