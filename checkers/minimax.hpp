#pragma once
#include <checkers/game.hpp>

class MiniMax {
 private:
  Game _game;

 public:
  Move choose_best_move();
};