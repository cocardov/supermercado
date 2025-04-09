cmake_minimum_required(VERSION 3.28)

project(supermercado)

add_subdirectory(./utils)

link_libraries(utils)
add_executable(supermercado ./main.cpp)

