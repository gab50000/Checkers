#include <checkers/minimax.hpp>

std::shared_ptr<Move> MiniMax::choose_best_move() {
  auto move = _game->get_moves()[0];
  return move;
}
