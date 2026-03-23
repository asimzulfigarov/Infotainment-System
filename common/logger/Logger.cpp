#include "Logger.h"

#include <iostream>
#include <iomanip>
#include <ctime>

std::string enm_to_string(LogLevel level){
    switch(level){
        case LogLevel::INFO: return "INFO";
                        break;
        case LogLevel::WARN: return "WARN";
                        break;
        case LogLevel::ERROR: return "ERROR";
                        break;
    }
    return "undifined log type";
}

Logger::Logger() : m_globalLevel(LogLevel::INFO) {}

Logger& Logger::getLogger(){
    static Logger logger;
    return logger;
}


void Logger::log(LogLevel level, const std::string& message){
    std::lock_guard<std::mutex> lock(mtx);
    std::time_t now = std::time(nullptr);
    if(level >= m_globalLevel)
        std::cout << "time: " << std::put_time(std::localtime(&now), "%H:%M:%S")<< ", type: " << enm_to_string(level) << ", message: " << message << std::endl;

}

void Logger::setLevel(const std::string& level){
        if(level == "INFO") m_globalLevel = LogLevel::INFO;
        if(level == "WARN") m_globalLevel = LogLevel::WARN;
        if(level == "ERROR") m_globalLevel = LogLevel::ERROR;
}


void Logger::setLevel(LogLevel level){
    m_globalLevel = level;
}

