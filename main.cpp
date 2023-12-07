#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/daily_file_sink.h"
void logInit(){
    auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info);
    spdlog::info("log init");
}

int main() {
    logInit();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press [Enter] key to continue...";
    std::cin.get();
    return 0;
}
