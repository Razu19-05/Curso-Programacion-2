cmake_minimum_required(VERSION 4.0)
project(UnaAplicacionConBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibliotecaEstatica main.cpp
        src/AuxiliaryFuctions.cpp
        src/AuxiliaryFuctions.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(UnaAplicacionConBibliotecaEstatica PRIVATE src)
