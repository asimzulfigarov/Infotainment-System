#include "ConfigLoader.h"

#include <iostream>

ConfigLoader::ConfigLoader() {}

void ConfigLoader::loadFromFile(const std::string& fileName){
    m_File.open(fileName);

    if (!m_File.is_open()) {
        throw std::runtime_error("Failed to open Configs.json");
    }

    if (m_File.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error("Configs.json is empty");
    }

    try {
    m_File >> j;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }
}

int ConfigLoader::getInt(const std::string& key, const std::string& value){
    int answer = j[key][value];
    return answer;
}
std::string ConfigLoader::getString(const std::string& key, const std::string& value){
    std::string answer = j[key][value];
    return answer;
}
bool ConfigLoader::getBool(const std::string& key, const std::string& value){
    bool answer = j[key][value];
    return answer;
}
float ConfigLoader::getFloat(const std::string& key, const std::string& value){
    float answer = j[key][value];
    return answer;
}