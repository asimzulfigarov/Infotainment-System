#pragma once

#include <string>
#include <mutex>

enum class LogLevel{
    INFO,
    WARN,
    ERROR
};


class Logger{
private:
    Logger();
private:
    LogLevel m_globalLevel;
    std::mutex mtx;
public:
    Logger(const Logger& obj) = delete;
    Logger& operator=(const Logger& obj) = delete;

    static Logger& getLogger();

public:
    void log(LogLevel level, const std::string& message);
    void setLevel(LogLevel level);
};