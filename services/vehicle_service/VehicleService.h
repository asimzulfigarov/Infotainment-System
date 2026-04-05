#pragma once

#include "VehicleSimulator.h"
#include "config/ConfigLoader.h"

class VehicleService{
 private:
    VehicleSimulator m_Simulator;
public:
    VehicleService(ConfigLoader& config);
    void start();
    void startEngine();
};