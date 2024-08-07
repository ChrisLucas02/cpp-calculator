cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_calculator main.cpp CCalculator.cpp CCalculator.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")