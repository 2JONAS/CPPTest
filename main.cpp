#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/daily_file_sink.h"
#include "include/AppConfig.h"
#include <httplib.h>
#include <yaml-cpp/yaml.h>
#include "spdlog/sinks/stdout_color_sinks.h"

void logInit(){

//    auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily.txt", 2, 30);
    spdlog::flush_every(std::chrono::seconds(1));
    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    logger.set_level(spdlog::level::debug);

    spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
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
    loadConfig();
    logInit();
    spdlog::info("log init");
    std::thread serverThread(listenServer);
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press [Enter] key to continue...";
    std::cin.get();
    serverThread.join();
    return 0;
}
