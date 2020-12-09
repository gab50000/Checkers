cmake_minimum_required(VERSION 3.18)

project(Checkers)

message(Hello)

set(CMAKE_CXX_STANDARD 17)

add_library(board STATIC checkers/board.hpp checkers/board.cpp)

add_executable(checkers checkers/main.cpp)