cmake_minimum_required(VERSION 3.17)
project(slim)

set(CMAKE_CXX_STANDARD 14)

add_executable(slim str.cpp str.h main.cpp print.hpp)