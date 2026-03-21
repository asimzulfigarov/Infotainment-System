cmake_minimum_required(VERSION 3.28.3)

project(InfotainmentSystem)

add_subdirectory(common)
add_subdirectory(services/vehicle_service)
add_subdirectory(services/system_controller)
add_subdirectory(services/media_service)
add_subdirectory(services/diagnostics_service)