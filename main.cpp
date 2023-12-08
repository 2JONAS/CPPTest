#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/daily_file_sink.h"
#include "include/AppConfig.h"
#include <httplib.h>
#include <yaml-cpp/yaml.h>

void logInit(){
    auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info);
    spdlog::info("log init");
}
void loadConfig() {
    AppConfig& config = AppConfig::getInstance();
    config.loadConfig("./static/config.yaml");
}
void listenServer(){
    httplib::Server svr;

    // 处理 GET 请求
    svr.Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        std::cout<<"Get Hello Request"<<std::endl;
        res.set_content("Hello World!", "text/plain");
    });

    // 启动服务器，监听端口 8080
    ;
    svr.listen(AppConfig::getInstance().listenIP, AppConfig::getInstance().listenPort);
}

int main() {
    logInit();
    loadConfig();
    listenServer();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press [Enter] key to continue...";
    std::cin.get();
    return 0;
}
