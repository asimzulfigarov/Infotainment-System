#include "TcpServer.h"

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "../logger/Logger.h"


TcpServer::TcpServer(int port) : m_port(port) {}


int TcpServer::start(){
    // 1. Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1){
        std::cerr << "Can't create a socket!";
        return -1;
    }

    // 2. Restart the port immideatly after program ends
    int opt = 1;
    setsockopt(listening, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 3. Bind the socket to an IP / PORT
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);


    if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1){
        perror("bind");
        return -2;
    }

    // 4. Mark the socket for listening
    if (listen(listening, SOMAXCONN) == -1){
        std::cerr << "Can't listen!";
        return -3;
    }

    std::cout << "[TcpServer] Listening on port " << m_port << std::endl;

    while(true){
        // Accept a call
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

            Logger::getLogger().log(LogLevel::INFO, "Received: " + msg);
            onMessageReceived(msg);
            
        }
        close(clientSocket);
    }
}



void TcpServer::setCommandHandler(std::shared_ptr<ICommandHandler> handler){
    m_handler = handler;
}

void TcpServer::onMessageReceived(const std::string& msg){
    if (m_handler){
        m_handler->handleCommand(msg);
    }
}


std::string TcpServer::processRequest(const std::string& msg){
    
    return "";
}