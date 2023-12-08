#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <string>
#include <ostream>

class AppConfig {
public:

    static AppConfig& getInstance();

    void loadConfig(const std::string& configFile);

    int listenPort=8082;
    std::string listenIP="0.0.0.0";

    friend std::ostream &operator<<(std::ostream &os, const AppConfig &config);

private:

    AppConfig();
    ~AppConfig();
    AppConfig(const AppConfig&) = delete;
    AppConfig& operator=(const AppConfig&) = delete;
};
#endif  // APPCONFIG_H