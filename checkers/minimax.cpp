#include <checkers/minimax.hpp>

CheckersMove MiniMax::choose_best_move() {
  auto move = _game.get_moves()[0];
  return move;
}
