cmake_minimum_required(VERSION 3.25)
project(cpp6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
# 头文件的另类引入方式
#set(SPDLOG_DIR "/home/wangxin/tmp/vcpkg/spdlog")
#set(HTTP_DIR "/home/wangxin/sft/cppmake/cpp-httplib")
#include_directories(${SPDLOG_DIR}/include)
#include_directories(${HTTP_DIR})

find_package(spdlog REQUIRED)
find_package(httplib REQUIRED)

# 源文件
add_executable(cpp6 main.cpp)

# 链接库
#target_link_libraries(cpp6 PRIVATE ${SPDLOG_DIR}/build/libspdlog.a)
target_link_libraries(cpp6 PRIVATE spdlog::spdlog)
target_link_libraries(cpp6 PRIVATE httplib::httplib)  # 这个库是make install的方式安装的