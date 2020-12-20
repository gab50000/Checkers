#include <checkers/board.hpp>
#include <memory>
#include <optional>

CheckersBoard empty_board() {
  auto board =
      std::vector(8, std::vector(8, static_cast<BoardState>(std::nullopt)));
  return board;
}

Token::Token(PlayerColor color, TokenType token_type)
    : color(color), token_type(token_type) {}

bool Token::operator==(const Token& other) {
  return (color == other.color) && (token_type == other.token_type);
}