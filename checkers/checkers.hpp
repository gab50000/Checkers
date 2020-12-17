#pragma once
#include <checkers/game.hpp>
#include <utility>

struct CheckersMove : Move {
  std::pair<int, int> from;
  std::pair<int, int> to;
};

class Checkers : Game {
  void make_move(CheckersMove move);
};