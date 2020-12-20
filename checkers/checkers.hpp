#pragma once
#include <checkers/board.hpp>
#include <memory>
#include <utility>

enum class Direction { Up, Down };

struct CheckersMove {
  std::pair<int, int> from;
  std::pair<int, int> to;

  CheckersMove(std::pair<int, int>, std::pair<int, int>);

  bool operator=(const CheckersMove&);
};

class CheckersGame {
 private:
  PlayerColor _current_player;
  CheckersBoard _board;
  Direction _direction;

 public:
  CheckersGame(PlayerColor, CheckersBoard, Direction);
  CheckersGame make_move(const CheckersMove&);
  CheckersBoard get_board();
  std::vector<CheckersMove> get_moves();
  std::vector<std::pair<int, int>> get_positions();
  std::vector<int> evaluate_moves(const std::vector<CheckersMove>&);
};