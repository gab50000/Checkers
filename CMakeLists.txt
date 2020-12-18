cmake_minimum_required(VERSION 3.18)
include(FetchContent)
include(GoogleTest)

project(Checkers)

message(Hello)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_library(board STATIC checkers/board.hpp checkers/board.cpp)
add_library(minimax checkers/minimax.cpp checkers/minimax.hpp)
add_library(game checkers/game.hpp)
add_library(checkers checkers/checkers.cpp checkers/checkers.hpp)
set_target_properties(game PROPERTIES LINKER_LANGUAGE CXX)

add_executable(checkers.exe checkers/main.cpp)

FetchContent_Populate(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
enable_testing()

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
add_executable(example_test tests/test.cpp)
add_executable(test_checkers tests/test_checkers.cpp)
target_link_libraries(example_test gtest_main)
target_link_libraries(test_checkers gtest_main checkers board)
add_test(NAME example_test COMMAND example_test)
add_test(NAME test_checkers COMMAND test_checkers)