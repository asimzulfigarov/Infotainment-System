#include "VehicleService.h"
#include "VehicleData.h"
#include "logger/Logger.h"


VehicleService::VehicleService(ConfigLoader& config) : m_Simulator(config.getInt("vehicle_service", "update_frequency_s")){

}

void VehicleService::start(){
    Logger::getLogger().log(LogLevel::INFO, "VehicleService started");

    m_Simulator.start();

    //Test
    while(true){
    VehicleData data = m_Simulator.getData();

    Logger::getLogger().log(LogLevel::INFO, "Speed=" + std::to_string(data.speed));
    Logger::getLogger().log(LogLevel::INFO, "Fuel=" + std::to_string(data.fuel));
    Logger::getLogger().log(LogLevel::INFO, "Engine Temperature=" + std::to_string(data.engineTemperature));

    std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}