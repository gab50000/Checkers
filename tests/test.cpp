#include <checkers/board.cpp>
#include <iostream>

#include "gtest/gtest.h"

TEST(CheckersTest, TestSomething) {
  auto board = empty_board();
  ASSERT_EQ(board[0][0], BoardState::empty);
}