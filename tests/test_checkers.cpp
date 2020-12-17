#include <checkers/board.hpp>
#include <checkers/checkers.hpp>
#include <iostream>
#include <utility>

#include "gtest/gtest.h"

TEST(CheckersTest, TestMove) {
  CheckersMove move({0, 0}, {1, 1});
  auto board = empty_board();
  std::cout << "Board: " << board.size() << std::endl;
  std::cout << "Board[0]: " << board[0].size() << std::endl;
  board[0][0] = BoardState::black_king;

  auto checkers = CheckersGame(board);
  checkers.make_move(move);
  auto new_board = checkers.get_board();

  EXPECT_EQ(new_board[0][0], BoardState::empty);
  EXPECT_EQ(new_board[1][1], BoardState::black_king);
}