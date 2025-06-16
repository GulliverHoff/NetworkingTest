cmake_minimum_required(VERSION 3.16)
project(TCP_Server)
 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(LOOPBACK "Listen only on loopback interface" ON)

add_executable(TCP_Server)
target_sources(TCP_Server PRIVATE main.cpp)

if(WIN32)
    message(STATUS "compiling Win32")
    target_include_directories(TCP_Server PRIVATE win32)
    target_link_libraries(TCP_Server PRIVATE ws2_32)
else()
    target_include_directories(TCP_Server PRIVATE os_fallback)
endif()

if(LOOPBACK)
    target_compile_definitions(TCP_Server PRIVATE LOOPBACK_LISTEN)
endif()