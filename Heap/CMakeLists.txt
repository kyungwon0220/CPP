cmake_minimum_required(VERSION 3.10)
project(MyHeap)
add_executable(MyHeap src/MyHeap.cpp src/main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
