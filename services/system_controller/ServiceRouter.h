#pragma once

#include "command_handler/CommandHandler.h"
#include "../vehicle_service/VehicleService.h"
#include "../media_service/MediaService.h"
#include "../diagnostics_service/DiagnosticsService.h"


class ServiceRouter : public ICommandHandler{
public:
    ServiceRouter(VehicleService& v) : m_vehicle(v) {}
    void handleCommand(const std::string& cmd) override {
        if (cmd == "START_ENGINE") m_vehicle.startEngine();
    }
private:
    VehicleService& m_vehicle;
};