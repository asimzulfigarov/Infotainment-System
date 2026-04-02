#pragma once

#include <string>

class TcpClient{
public:
    std::string sendRequest(const std::string& ip, int port, const std::string& message);
};