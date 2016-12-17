#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int server_handshake(int *fromClient){

  mkfifo("mario", 0644);
  int *fromClient = open("./client.c", O_RDONLY, 0644);
  char buffer[1000];

}
