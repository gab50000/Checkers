#include <checkers/board.hpp>
#include <checkers/checkers.hpp>
#include <utility>

#include "gtest/gtest.h"

TEST(CheckersTest, TestMove) {
  CheckersMove move({0, 0}, {1, 1});
  auto board = empty_board();
  board[0][0] = BoardState::black_king;

  auto checkers = CheckersGame(PlayerColor::white, board, Direction::Up);
  checkers.make_move(move);
  auto new_board = checkers.get_board();

  EXPECT_EQ(new_board[0][0], BoardState::empty);
  EXPECT_EQ(new_board[1][1], BoardState::black_king);
}

TEST(CheckersTest, TestGetMoves) {
  auto board = empty_board();
  board[3][3] = BoardState::black_man;
  board[2][2] = BoardState::white_man;

  auto checkers = CheckersGame(PlayerColor::white, board, Direction::Up);

  auto moves = checkers.get_moves();

  EXPECT_EQ(moves.size(), 1);

  auto* mv = static_cast<CheckersMove*>(moves[0].get());
  auto from_target = std::make_pair(2, 2);
  auto to_target = std::make_pair(2, 2);
  EXPECT_EQ(mv->from, from_target);
}