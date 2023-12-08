#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/daily_file_sink.h"
#include <httplib.h>
void logInit(){
    auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info);
    spdlog::info("log init");
}
void listenServer(){
    httplib::Server svr;

    // 处理 GET 请求
    svr.Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });

    // 启动服务器，监听端口 8080
    svr.listen("0.0.0.0", 8082);
}

int main() {
    logInit();
    listenServer();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press [Enter] key to continue...";
    std::cin.get();
    return 0;
}
