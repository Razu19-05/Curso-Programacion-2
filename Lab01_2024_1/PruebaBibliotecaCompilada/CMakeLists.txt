cmake_minimum_required(VERSION 4.0)
project(PruebaBibliotecaCompilada)

set(CMAKE_CXX_STANDARD 20)

add_executable(PruebaBibliotecaCompilada main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(PruebaBibliotecaCompilada PRIVATE src)
