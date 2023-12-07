cmake_minimum_required(VERSION 3.25)
project(cpp6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(SPDLOG_DIR "/home/wangxin/tmp/vcpkg/spdlog")
# 头文件
include_directories(${SPDLOG_DIR}/include)

# 源文件
add_executable(cpp6 main.cpp)

# 链接库
target_link_libraries(cpp6 ${SPDLOG_DIR}/build/libspdlog.a)