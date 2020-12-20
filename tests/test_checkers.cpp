#include <checkers/board.hpp>
#include <checkers/checkers.hpp>
#include <memory>
#include <optional>
#include <utility>

#include "gtest/gtest.h"

TEST(CheckersTest, TestMove) {
  CheckersMove move({0, 0}, {1, 1});
  auto board = empty_board();
  board[0][0] = std::make_optional<Token>(PlayerColor::black, TokenType::King);

  auto checkers = CheckersGame(PlayerColor::white, board, Direction::Up);
  checkers.make_move(move);
  auto new_board = checkers.get_board();

  auto target = Token{PlayerColor::black, TokenType::King};
  auto val = new_board[1][1].value();
  EXPECT_FALSE(new_board[0][0].has_value());
  EXPECT_TRUE(val == target);
}

TEST(CheckersTest, TestGetPositions) {
  auto board = empty_board();
  board[3][3] = std::make_optional<Token>(PlayerColor::black, TokenType::Man);
  auto checkers = CheckersGame(PlayerColor::black, board, Direction::Up);

  auto positions = checkers.get_positions();

  EXPECT_EQ(positions.size(), 1);

  auto pos = positions[0];
  auto target = std::pair<int, int>{3, 3};

  EXPECT_EQ(pos, target);
}
TEST(CheckersTest, TestGetMoves) {
  auto board = empty_board();
  board[3][3] = std::make_optional<Token>(PlayerColor::black, TokenType::Man);
  board[2][2] = std::make_optional<Token>(PlayerColor::white, TokenType::Man);

  auto checkers = CheckersGame(PlayerColor::white, board, Direction::Up);

  auto moves = checkers.get_moves();

  EXPECT_EQ(moves.size(), 1);

  auto mv = moves[0];
  auto from = static_cast<CheckersMove*>(mv.get())->from;
  auto from_target = std::make_pair(2, 2);
  auto to_target = std::make_pair(2, 2);

  EXPECT_EQ(from, from_target);
}