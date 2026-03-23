add_executable(vehicle_service main.cpp VehicleService.cpp VehicleSimulator.cpp)

target_link_libraries(vehicle_service common)