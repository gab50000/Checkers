#pragma once
#include <checkers/board.hpp>
#include <checkers/game.hpp>
#include <utility>

struct CheckersMove : Move {
  std::pair<int, int> from;
  std::pair<int, int> to;

  CheckersMove(std::pair<int, int>, std::pair<int, int>);

  void make_move(CheckersMove);
};

class Checkers : Game {
 private:
  CheckersBoard _board;

 public:
  Checkers(CheckersBoard);
  void make_move(Move&);
  CheckersBoard get_board();
};