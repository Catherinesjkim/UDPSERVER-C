// https://github.com/nikhilroxtomar/UDP-Client-Server-Program-in-C

// UDP Server in C
// libraries that we are going to use

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{

    int port = 5501;
    int sockfd;
    struct sockaddr_in myaddr, remoteAddr;
    char buffer[1024];
    socklen_t addr_size;

    // AF_INET: IPv4 version, family, UDP.
    // sockfd: Socket File Descript - This number is used by the OS to identify when a datagram comes, it will hash all of the source, destination, where the socket description lives.
    // It's a pointer to a table of where actually lives in the memory lives.
    // Default is 10k but you can increase that.
    // Memory is dynamically allocated with JS but you have to do it everything yourself with C.
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&myaddr, '\0', sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(port);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Only when you bind, things actually happen. Who are you? I have no idea
    bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    addr_size = sizeof(remoteAddr);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&remoteAddr, &addr_size);
    printf("got data from %s ", buffer);
    return 0;
}
