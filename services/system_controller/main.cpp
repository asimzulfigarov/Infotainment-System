#include <iostream>
#include "ServiceRouter.h"
#include "../vehicle_service/VehicleService.h"
#include "../media_service/MediaService.h"
#include "../diagnostics_service/DiagnosticsService.h"
#include "logger/Logger.h"
#include "config/ConfigLoader.h"
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
    // get and init the cofing
    ConfigLoader config;
    init(config);
    
    // Create and start services
    VehicleService vehicleService(config);
    vehicleService.start();

    // start the Router
    auto router = std::make_shared<ServiceRouter>(vehicleService);

    // TCP server
    int port = config.getInt("vehicle_service", "port");
    TcpServer server(port);
    server.setCommandHandler(router);
    server.start();
    
}