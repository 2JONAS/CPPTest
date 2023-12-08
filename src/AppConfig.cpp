#include "../include/AppConfig.h"
#include <iostream>
#include <yaml-cpp/yaml.h>

AppConfig& AppConfig::getInstance() {
    static AppConfig instance;
    return instance;
}

void AppConfig::loadConfig(const std::string& configFile) {
    try {
        YAML::Node config = YAML::LoadFile(configFile);
        if (config["listenPort"]) {
            listenPort = config["listenPort"].as<int>();
        }
        if (config["listenIP"]) {
            listenIP = config["listenIP"].as<std::string>();
        }
    } catch (const YAML::Exception& e) {
        std::cerr << "Error loading YAML configuration: " << e.what() << std::endl;
        // 处理加载配置失败的情况
    }
    std::cout<<"config is: "<< *this << std::endl;
}

AppConfig::AppConfig() {

}

std::ostream &operator<<(std::ostream &os, const AppConfig &config) {
    os << "listenPort: " << config.listenPort << " listenIP: " << config.listenIP;
    return os;
}


AppConfig::~AppConfig() = default;