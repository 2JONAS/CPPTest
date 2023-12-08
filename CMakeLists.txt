cmake_minimum_required(VERSION 3.25)
project(cpp6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
# 头文件的另类引入方式
#set(SPDLOG_DIR "/home/wangxin/tmp/vcpkg/spdlog")
#set(HTTP_DIR "/home/wangxin/sft/cppmake/cpp-httplib")
#include_directories(${SPDLOG_DIR}/include)
#include_directories(${HTTP_DIR})

set(CMAKE_PREFIX_PATH "/usr/local/include/")
find_package(spdlog REQUIRED)
find_package(httplib REQUIRED)
find_package(yaml-cpp REQUIRED)


add_custom_target(remove_static_folder ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/static
        COMMENT "Removing static folder from build directory"
)
file(COPY static DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# 源文件
# 获取源文件列表
file(GLOB SOURCES src/*.cpp)
# 获取头文件列表
file(GLOB HEADERS include/*.h)
#add_executable(cpp6 main.cpp
#        ${SOURCES} ${HEADERS})
add_executable(cpp6 main.cpp
        src/AppConfig.cpp
        include/AppConfig.h)


# 链接库
#target_link_libraries(cpp6 PRIVATE ${SPDLOG_DIR}/build/libspdlog.a)
target_link_libraries(cpp6 PRIVATE spdlog::spdlog)
target_link_libraries(cpp6 PRIVATE httplib::httplib)  # 这个库是make install的方式安装的
target_link_libraries(cpp6 PRIVATE yaml-cpp::yaml-cpp)