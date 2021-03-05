#include <checkers/board.hpp>
#include <memory>
#include <optional>
#include <ostream>

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

std::ostream& operator<<(std::ostream& os, const Token& token) {
  if (token.color == PlayerColor::white && token.token_type == TokenType::Man) {
    os << "●";
  } else if (token.color == PlayerColor::black &&
             token.token_type == TokenType::Man) {
    os << "o";
  } else if (token.color == PlayerColor::white &&
             token.token_type == TokenType::King) {
    os << "♚";
  } else if (token.color == PlayerColor::black &&
             token.token_type == TokenType::King) {
    os << "♔";
  }
  return os;
}