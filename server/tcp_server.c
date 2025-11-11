#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#include <arpa/inet.h>


#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main() {

    struct sockaddr_in serveraddr, cli;
    //initialize a socket connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("socket is not created!!");
        exit(1);
    }
    printf("socket is successfully created");

    bzero(&serveraddr, sizeof(serveraddr));

    //Assign IP, PORT
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(PORT);

    //connect client socket -> server socket
    int connfd = connect(sockfd, (SA*) &serveraddr, sizeof(serveraddr));
    if (connfd != 0)
    {
       perror("connection with the server failed!!");
       exit(1);
    }
    printf("connected to server ...");


    // func(sockfd);

    //close socket
    close(sockfd);
    return 0;
}

void func(int sockfd) {
    //chat func
}