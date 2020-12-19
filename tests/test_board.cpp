#include <checkers/board.hpp>
#include <optional>

#include "gtest/gtest.h"

TEST(BoardTest, BoardConstruction) {
  auto board = empty_board();
  auto val = *(board[0][0]);
}