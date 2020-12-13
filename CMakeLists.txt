cmake_minimum_required(VERSION 3.18)
include(FetchContent)

project(Checkers)

message(Hello)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_library(board STATIC checkers/board.hpp checkers/board.cpp)

add_executable(checkers checkers/main.cpp)

FetchContent_Populate(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
add_executable(example_test tests/test.cpp)
target_link_libraries(example_test gtest_main)
add_test(NAME example_test COMMAND example_test)