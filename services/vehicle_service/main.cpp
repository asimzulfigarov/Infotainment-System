#include <iostream>
#include "logger/Logger.h"
#include "config/ConfigLoader.h"
#include "VehicleService.h"
#include "ipc/TcpServer.h"

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

        TcpServer server(54000);
        server.start();

    ConfigLoader config;
    init(config);
    

    Logger::getLogger().log(LogLevel::INFO, "Engine start!");
    Logger::getLogger().log(LogLevel::WARN, "Carburetor yellow check!");

    //start the service
    VehicleService service(config);
    service.start();

    return 0;
}