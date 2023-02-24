cmake_minimum_required(VERSION 3.10)
project(MyCircularQueue)
add_executable(MyCircularQueue src/main.cpp src/CircularQueue.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)