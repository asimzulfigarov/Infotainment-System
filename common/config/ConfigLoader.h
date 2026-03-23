#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

class ConfigLoader{
private:
    std::ifstream m_File;
    nlohmann::json j;
public:
    ConfigLoader();
    void loadFromFile(const std::string& filaName);
    int getInt(const std::string& key, const std::string& value);
    std::string getString(const std::string& key, const std::string& value);
    bool getBool(const std::string& key, const std::string& value);
    float getFloat(const std::string& key, const std::string& value);
};