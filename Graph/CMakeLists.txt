cmake_minimum_required(VERSION 3.10)
project(MyGraph)
add_executable(MyGraph src/MyGraph.cpp src/main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
