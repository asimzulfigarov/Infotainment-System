#include "TcpServer.h"

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

TcpServer::TcpServer(int port) : m_port(port) {}


void TcpServer::start(){
    int listening = socket(AF_INET, SOCK_STREAM, 0);


    int opt = 1;
    setsockopt(listening, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));
    listen(listening, SOMAXCONN);

    std::cout << "[TcpServer] Listening on port" << m_port << std::endl;

    while(true){
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

        char buf[4096];

        while(true){
            memset(buf, 0, 4096);
            int bytesRecv = recv(clientSocket, buf, 4096, 0);

            if(bytesRecv <= 0) break;

            std::string msg(buf, bytesRecv); //- how come buf + int becomes string
            std::cout << "[TcpServer] Received: " << msg << std::endl;

            std::string response  = "Echo: " + msg;
            send(clientSocket, response.c_str(), response.size(), 0);
        }
        close(clientSocket);
    }
}
