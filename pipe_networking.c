#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int server_handshake(int *fromClient){

  //step 1
  mkfifo("mario", 0644);
  printf("[SERVER] Starting server: created well known pipe\n");

  //step2
  printf("[SERVER] Waiting for client connection...\n");
  *fromClient = open("mario", O_RDONLY, 0644);

  //step 6
  char fifoName[1024];
  read(*fromClient, fifoName, 1024);
  printf("[SERVER] Received client message\n");
  unlink("mario");
  
  //step 7
  int private = open(fifoName, O_WRONLY);
  char message[] = "Hello Client!";
  write(private, message, strlen(message));
  printf("[SERVER] Connected to client\n [SERVER] Wrote to client");

  //step 9
  char clientMessage[1024];  
  read(*fromClient, clientMessage, 1024);
  printf("\n[SERVER] Recived client message: %s\n", clientMessage);

  return private;
}

int client_handshake(int *toServer){

  //step 3
  char fifoName[1024];
  sprintf(fifoName, "%d", getpid());
  mkfifo(fifoName, 0644);
  printf("[CLIENT] Created private FIFO %s\n", fifoName);

  //step 4
  printf("[CLIENT] Sent FIFO name to server\n");
  *toServer = open("mario", O_WRONLY);
  write(*toServer, fifoName, strlen(fifoName));

  //step 5
  printf("[CLIENT] Waiting for server connection...\n");
  int private = open(fifoName, O_RDONLY);

  //step 8
  char serverMessage[1024];
  read(private, serverMessage,1024);
  printf("[CLIENT] Received server message\n");

  unlink(fifoName);

  //step 9
  char clientMessage[] = "Hello Server!";
  write(*toServer, clientMessage, strlen(clientMessage));
  printf("[CLIENT] Sent message to server\n[CLIENT] Connected to server :)\n");

  return private;
}
