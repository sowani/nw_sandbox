#include "inet.h"

void str_cli (int);

int main (int argc, char **argv)
{
  int sockfd;
  struct sockaddr_in serv_addr;

#if 1
  bzero ((char *) &serv_addr, sizeof (serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr (SERV_HOST_ADDR);
  serv_addr.sin_port = htons (SERV_TCP_PORT);

  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror ("socket");
    return (1);
  }
  if (connect (sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0)
  {
    perror ("connect");
    close (sockfd);
    return (1);
  }
#endif
  str_cli (sockfd);
  close (sockfd);
  return (0);
}

void str_cli (int fd)
{
  int i, size;
  Packet packet;

  i = size = 0;
  packet.cmd = 1;
  packet.size = 6;
/*
  packet.buf = (unsigned char *) malloc (size * sizeof (unsigned char));
*/
  bzero (packet.buf, size);
  strcpy (packet.buf, "hello\0");
  size = (2 * sizeof (int)) + 
         (6 * sizeof (unsigned char));

  /* send */
  write (fd, (void *) &packet, size);
}
