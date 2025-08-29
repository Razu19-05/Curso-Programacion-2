cmake_minimum_required(VERSION 4.0)
project(ProyectoPrincipal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPrincipal main.cpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(ProyectoPrincipal PRIVATE src)