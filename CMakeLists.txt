## Main CMakeLists of the Design Patterns project
cmake_minimum_required(VERSION 3.10)

## This is a C++ only project
project("Design Patterns in C++" CXX)

## Include the third partys
include_directories(3rdparty)

## CMake binary dir
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
message("-- Setting binary dir to: ${CMAKE_BINARY_DIR}")

## Add the subdirectories and their CMakeLists
add_subdirectory(patterns)


