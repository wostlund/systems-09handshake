#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int server_handshake(int *x){
  mkfifo("mario", 0644);
  x=open("luigi", O_RDONLY);
  read(
}
