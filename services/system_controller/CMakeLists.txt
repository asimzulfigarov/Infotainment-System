add_executable(system_controller
    main.cpp
    ../media_service/MediaService.cpp
    ../diagnostics_service/DiagnosticsService.cpp
)

target_link_libraries(system_controller 
    common
    vehicle_service
)