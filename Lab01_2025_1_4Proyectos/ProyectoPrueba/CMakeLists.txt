cmake_minimum_required(VERSION 4.0)
project(ProyectoPrueba)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPrueba main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(ProyectoPrueba PRIVATE src)
