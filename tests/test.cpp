#include <checkers/board.cpp>
#include <iostream>

#include "gtest/gtest.h"

TEST(BoardTest, TestSomething) {
  auto board = empty_board();
  ASSERT_EQ(board[0][0], BoardState::empty);
}