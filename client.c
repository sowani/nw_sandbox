#include "inet.h"
#include "header.h"

#define psize 524268

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
  KesPacket packet;
  unsigned char data[psize];  /* 512 - 20 */

  for (i = 0; i < psize; i++)
    data[i] = 0x2;

  /* Populate payload first */
  packet.pHdr.packetLen = psize;
  packet.pHdr.packetID = 0x1;
  packet.pHdr.protocolID = 0x0;
  packet.pHdr.destType = SC;
  packet.pHdr.priority = NORMAL;
  packet.pHdr.pduType = NO_ACK;
  packet.pHdr.messageType = HANDSHAKE;
  packet.pHdr.ackID = 0;
  /* packet.data = (unsigned char *) malloc (492 * sizeof (unsigned char)); */
  memcpy (packet.data, data, psize);
  packet.pHdr.reserved1 = 0x0;
  packet.pHdr.reserved2 = 0x0;
  packet.pHdr.reserved3 = 0x0;

  i = size = 0;
/*
  packet.buf = (unsigned char *) malloc (size * sizeof (unsigned char));
*/
  size = sizeof (packet.pHdr) + sizeof (data);
  size = 512 * 1024;
  printf ("sending %d bytes of data\n", size);

  /* send */
  write (fd, (void *) &packet, size);
}
