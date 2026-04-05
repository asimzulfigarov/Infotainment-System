# CMakeLists.txt for vehicle_service
add_library(vehicle_service
    VehicleService.cpp
    VehicleSimulator.cpp
)

target_link_libraries(vehicle_service
    common
)