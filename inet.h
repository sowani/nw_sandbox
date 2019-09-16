#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SERV_TCP_PORT 6008
#define SERV_HOST_ADDR "127.0.0.1"

/*
#define SERV_TCP_PORT 42000
#define SERV_HOST_ADDR "10.44.119.19"
*/

/*
typedef struct
{
  int cmd;
  int size;
  unsigned char buf[20];
} Packet;
*/
