#pragma once
#include <checkers/board.hpp>
#include <checkers/game.hpp>
#include <memory>
#include <utility>

enum class Direction { Up, Down };

enum class PlayerColor { white, black };

struct CheckersMove : Move {
  std::pair<int, int> from;
  std::pair<int, int> to;

  CheckersMove(std::pair<int, int>, std::pair<int, int>);

  void make_move(CheckersMove);
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