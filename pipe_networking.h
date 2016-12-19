#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MESSAGE_BUFFER_SIZE 1024

int server_handshake(int *fromClient);
int client_handshake(int *toServer);

