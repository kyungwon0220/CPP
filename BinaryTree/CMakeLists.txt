cmake_minimum_required(VERSION 3.10)
project(MyTree)
add_executable(MyTree src/main.cpp src/이진트리순회연산.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
