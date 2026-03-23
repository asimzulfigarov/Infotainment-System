#pragma once

#include <thread>
#include <atomic>
#include <mutex>
#include "VehicleData.h"

class VehicleSimulator{
private:
    VehicleData m_data;
    int m_interval;

    std::thread worker;
    std::atomic<bool> running{false};
    std::mutex mtx;

public:
    VehicleSimulator(int updateIntervalMs);
    void start();
    void stop();
    VehicleData getData();

private:
    void run();
};