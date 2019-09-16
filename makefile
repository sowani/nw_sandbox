default: all

all: server client

client:	client.c inet.h
	cc -g -o client client.c -lnsl

server:	server.c inet.h
	cc -g -o server server.c -lnsl

clean:
	\rm -f client server *.o
