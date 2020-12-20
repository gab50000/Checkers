#pragma once
#include <checkers/checkers.hpp>
#include <memory>

class MiniMax {
 private:
  CheckersGame _game;

 public:
  CheckersMove choose_best_move();
};