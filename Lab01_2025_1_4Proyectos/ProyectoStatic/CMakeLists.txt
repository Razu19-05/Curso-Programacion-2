cmake_minimum_required(VERSION 4.0)
project(ProyectoStatic)

set(CMAKE_CXX_STANDARD 20)

add_library(src STATIC src/Overloads.cpp)

add_executable(ProyectoStatic main.cpp)

target_link_libraries(ProyectoStatic src)
