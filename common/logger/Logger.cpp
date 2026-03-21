#include "Logger.h"

std::string enm_to_string(LogLevel level){
    switch(level){
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARN: return "WARN";
        case LogLevel::ERROR: return "ERROR";
    }
}

static Logger& Logger::getLogger(){
    static Logger logger;
    return logger;
}



void Logger::log(LogLevel level, const std::string& message){
    std::cout << "type: " << enm_to_string(level) << ", message: " << message << std::endl;
}

