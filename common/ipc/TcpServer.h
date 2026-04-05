#pragma once

#include <string>
#include <memory>

#include "../command_handler/CommandHandler.h"

class TcpServer{
public:
    TcpServer(int port);
    int start();
    std::string processRequest(const std::string& msg);
    void setCommandHandler(std::shared_ptr<ICommandHandler> handler);
    void onMessageReceived(const std::string& msg);
private:
    int m_port;
    std::string m_msg;
    std::shared_ptr<ICommandHandler> m_handler;
};