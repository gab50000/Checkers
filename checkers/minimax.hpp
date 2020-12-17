#pragma once
#include <checkers/game.hpp>
#include <memory>

class MiniMax {
 private:
  std::shared_ptr<Game> _game;

 public:
  std::shared_ptr<Move> choose_best_move();
};