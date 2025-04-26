cmake_minimum_required(VERSION 3.17)

project(oop_laba4)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(main main.cpp myvector.hpp)
