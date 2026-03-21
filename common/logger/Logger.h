#pragma once


enum class LogLevel{
    INFO,
    WARN,
    ERROR
};


class Logger{
private:
    Logger();
public:
    Logger(const Logger& obj) = delete;
    Logger& operator=(const Logger& obj) = delete;

    static Logger& getLogger();

public:
    void log(LogLevel level, const std::string& message);
};