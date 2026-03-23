#include "VehicleSimulator.h"
#include <chrono>

VehicleSimulator::VehicleSimulator(int updateIntervalMs) : m_interval(updateIntervalMs){

}
void VehicleSimulator::start(){
    running = true;
    worker = std::thread(&VehicleSimulator::run, this);
}
void VehicleSimulator::stop(){
    running = false;
    if(worker.joinable())
        worker.join();
}
VehicleData VehicleSimulator::getData(){
    std::lock_guard<std::mutex> lock(mtx);
    return m_data;
}

void VehicleSimulator::run(){
    while(running){
        std::lock_guard<std::mutex> lock(mtx);

        if(m_data.speed < 120)
            m_data.speed += 5;

        if(m_data.fuel > 0)
            m_data.fuel -= 1;

        m_data.engineTemperature += 0.5f;

        if (m_data.engineTemperature > 120.0f)
            m_data.engineTemperature = 120.0f;

            std::this_thread::sleep_for(std::chrono::seconds(m_interval)); // temp
    }
    std::this_thread::sleep_for(std::chrono::seconds(m_interval)); // temp
}