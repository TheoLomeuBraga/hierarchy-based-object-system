cmake_minimum_required(VERSION 3.10)
project(HierarchyBasedObjectSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(test test/test.cpp)