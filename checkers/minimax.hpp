#pragma once
#include <checkers/checkers.hpp>
#include <memory>

class MiniMax {
 private:
  std::shared_ptr<CheckersGame> _game;

 public:
  std::shared_ptr<CheckersMove> choose_best_move();
};