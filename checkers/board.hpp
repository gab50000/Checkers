#pragma once

#include <memory>
#include <optional>
#include <vector>

enum class PlayerColor { white, black };

enum class TokenType { Man, King };

struct Token {
  PlayerColor color;
  TokenType token_type;

  Token(PlayerColor, TokenType);

  bool operator==(const Token&);
};

using BoardState = std::optional<Token>;

using CheckersBoard = std::vector<std::vector<BoardState>>;

CheckersBoard empty_board();