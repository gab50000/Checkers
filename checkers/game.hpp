#pragma once
#include <memory>
#include <vector>

enum class Player { Black, White };

class Move {};

struct Game {
  Player current_player;
  std::vector<std::unique_ptr<Move>> get_moves();
};