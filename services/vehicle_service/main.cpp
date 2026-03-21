#include <iostream>
#include "logger/Logger.h"

int main(){

    Logger::getLogger().log(LogLevel::ERROR, "Engine failure");

    Logger::getLogger().setLevel(LogLevel::ERROR);

    Logger::getLogger().log(LogLevel::INFO, "Engine start");


    return 0;
}