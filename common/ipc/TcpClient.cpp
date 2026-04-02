#include "TcpClient.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


std::string TcpClient::sendRequest(const std::string& ip, int port, const std::string& message){
    int sock = socket(AF_INET, SOCK_STREAM, 0);


    sockaddr_in hint;
    hint.sin_family = AF_INET; // where do we specify ip address??
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr); // wjat is c_str???
    connect(sock, (sockaddr*)&hint, sizeof(hint));

    send(sock, message.c_str(), message.size(), 0); // what is zero here and in all the other places


    char buf[4096];
    memset(buf, 0, 4069);  // what is memset

    int bytesRecv = recv(sock, buf, 4096, 0);

    close (sock);

    return std::string(buf, bytesRecv);

}