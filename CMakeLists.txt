cmake_minimum_required(VERSION 3.16)
project(TCP_Server)
 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TCP_Server)

target_sources(TCP_Server PRIVATE main.cpp)

if(WIN32)
    target_link_libraries(TCP_Server PRIVATE ws2_32)
endif()