#include <checkers/board.hpp>

CheckersBoard empty_board() {
  return std::vector(8, std::vector(8, BoardState::empty));
}