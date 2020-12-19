#include <checkers/board.hpp>
#include <memory>
#include <optional>

CheckersBoard empty_board() {
  CheckersBoard vec;

  for (int i = 0; i < 8; ++i) {
    std::vector<std::unique_ptr<BoardState>> row;
    for (int j = 0; j < 8; ++j) {
      row.push_back(std::move(
          std::make_unique<BoardState>(PlayerColor::black, TokenType::King)));
    }
    vec.push_back(std::move(row));
  }
  return vec;
}

Token::Token(PlayerColor color, TokenType token_type)
    : color(color), token_type(token_type) {}

bool Token::operator==(const Token& other) {
  return (color == other.color) && (token_type == other.token_type);
}