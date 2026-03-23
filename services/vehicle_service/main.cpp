#include <iostream>
#include "logger/Logger.h"
#include "config/ConfigLoader.h"

void init(ConfigLoader& config){            //helper function to init the service
config.loadFromFile("../../../configs/configs.json");

    std::string level;

    try{
        level = config.getString("logging", "level");
    } catch(...) {
        throw "Failed to retrieve Log Level from config";
    }

    Logger::getLogger().setLevel(level);
}

int main(){

    ConfigLoader config;
    init(config);
    

    Logger::getLogger().log(LogLevel::INFO, "Engine start!");
    Logger::getLogger().log(LogLevel::WARN, "10'%' fuel!");
    //start the service

    return 0;
}