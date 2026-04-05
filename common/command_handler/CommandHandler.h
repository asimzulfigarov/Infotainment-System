#pragma once
#include <string>

class ICommandHandler{
public:
    virtual ~ICommandHandler() = default;
    virtual void handleCommand(const std::string& command) = 0;
};