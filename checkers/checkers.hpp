#pragma once
#include <checkers/board.hpp>
#include <checkers/game.hpp>
#include <memory>
#include <utility>

enum class Direction { Up, Down };

struct CheckersMove : Move {
  std::pair<int, int> from;
  std::pair<int, int> to;

  CheckersMove(std::pair<int, int>, std::pair<int, int>);

  bool operator=(const CheckersMove&);
};

class CheckersGame : Game {
 private:
  PlayerColor _current_player;
  CheckersBoard _board;
  Direction _direction;

 public:
  CheckersGame(PlayerColor, CheckersBoard, Direction);
  void make_move(Move&);
  CheckersBoard get_board();
  std::vector<std::shared_ptr<Move>> get_moves();
  std::vector<std::pair<int, int>> get_positions();
};