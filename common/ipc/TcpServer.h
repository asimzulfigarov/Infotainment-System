#pragma once

#include <string>


class TcpServer{
public:
    TcpServer(int port);
    void start();
private:
    int m_port;
};