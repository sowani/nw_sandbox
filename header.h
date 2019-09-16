typedef enum protocolType
{
  IP = 1,
  UART = 2
} PROTOTYPE;

typedef enum DestType
{
  PC = 1,
  SC,
  EA,
  TA,
  ALL = 255
} DESTTYPE;

typedef enum priorityType
{
  NORMAL = 0,
  CRITICAL,
  LIFE_SAFETY
} PRIORITY;

typedef enum pduType
{
  SEND_ACK = 0,
  NO_ACK,
  SIMPLE_ACK,
  COMPLX_ACK,
  ERROR_ACK
} PDUTYPE;

typedef enum MsgType
{
  HANDSHAKE = 0,
  UTILITY_DATA,
  LOAD_DATA,
  TIME_SYNC,
  EVENT_RECORD,
  DEBUG_LOG,
  ADAPTER_FW,
  OTHER
} MSGTYPE;

typedef struct kes_payload_hdr
{
  int packetLen;
  int packetID;
  unsigned char protocolID;
  unsigned char reserved1;
  unsigned char destType;
  unsigned char priority;
  unsigned char pduType;
  unsigned char messageType;
  unsigned char reserved2;
  unsigned char reserved3;
  int ackID;
} KesPayloadHdr;

typedef struct kes_packet
{
  KesPayloadHdr pHdr;
  unsigned char data[524268];
} KesPacket;
