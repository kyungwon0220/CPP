cmake_minimum_required(VERSION 3.10)
project(MyTree)
add_executable(MyTree src/BinarySearchTree.cpp src/main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
