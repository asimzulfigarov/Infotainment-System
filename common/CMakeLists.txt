add_library(common 
    logger/Logger.cpp
    config/ConfigLoader.cpp
    ipc/TcpServer.cpp
    ipc/TcpClient.cpp
)

target_include_directories(common PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}    # common headers
)