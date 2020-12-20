#include <checkers/board.hpp>
#include <memory>
#include <optional>

#include "gtest/gtest.h"

TEST(BoardTest, EmptyBoardConstruction) {
  auto board = empty_board();

  auto val = board[0][0];
  EXPECT_FALSE(val.has_value());
}

TEST(BoardTest, BoardWithToken) {
  auto board = empty_board();

  board[0][0] = Token{PlayerColor::black, TokenType::King};
  EXPECT_TRUE(board[0][0].has_value());
  EXPECT_EQ(board[0][0].value().color, PlayerColor::black);
}