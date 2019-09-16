#include "inet.h"
#include "header.h"

void str_echo (int sock_fd);
int SIZE = 512 * 1024;

int main (argc, argv)
int argc;
char **argv;
{
  int sockfd, newsockfd, clilen, childpid;
  struct sockaddr_in cli_addr, serv_addr;
  int i;

  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror ("socket");
    return (1);
  }

  bzero ((char *) &serv_addr, sizeof (serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
  serv_addr.sin_port = htons (SERV_TCP_PORT);

  if (bind (sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0)
  {
    perror ("bind");
    close (sockfd);
    return (1);
  }
  listen (sockfd, 3);

  for (i = 0; i < 1; i++)
  {
    clilen = sizeof (cli_addr);
    newsockfd = accept (sockfd, (struct sockaddr *) &cli_addr, &clilen);

    str_echo (newsockfd);
    close (newsockfd);
  }
  close (sockfd);
}

void str_echo (int sock_fd)
{
  int n, i;
  KesPacket packet;
  unsigned char *ptr;

  i = n = 0;
  n = read (sock_fd, &packet, SIZE);
  if (n > 0)
  {
    printf ("packetLen = %d\n", packet.pHdr.packetLen);
    printf ("packetID = %d\n", packet.pHdr.packetID);
    printf ("protocolID = %d\n", packet.pHdr.protocolID);
    printf ("destType = %d\n", packet.pHdr.destType);
    printf ("priority = %d\n", packet.pHdr.priority);
    printf ("pduType = %d\n", packet.pHdr.pduType);
    printf ("messageType = %d\n", packet.pHdr.messageType);
    /*printf ("data = %s\n", packet.data);*/

    ptr = &packet.data[0];
    for (i = 0; i < packet.pHdr.packetLen; i++, ptr++)
      printf ("%x ", *ptr);

    printf ("\n");
  }
  close (sock_fd);
  return;
}
