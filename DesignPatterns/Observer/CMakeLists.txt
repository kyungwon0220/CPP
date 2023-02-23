cmake_minimum_required(VERSION 3.10)
project(MyObserverPattern)
add_executable(MyObserverPattern src/main.cpp src/Observer.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
