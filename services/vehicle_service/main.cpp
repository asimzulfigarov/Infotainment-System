#include <iostream>
#include "logger/Logger.h"

int main(){

    Logger::getLogger().log(LogLevel::INFO, "Engine Start");

    return 0;
}