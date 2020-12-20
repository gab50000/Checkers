#include <checkers/checkers.hpp>
#include <iostream>

CheckersMove::CheckersMove(std::pair<int, int> from, std::pair<int, int> to)
    : from(from), to(to){};

bool CheckersMove::operator=(const CheckersMove& other) {
  return (from == other.from) && (to == other.to);
}

void CheckersGame::make_move(Move& move) {
  auto& checkers_move = static_cast<CheckersMove&>(move);
  auto [i, j] = checkers_move.from;
  auto [ii, jj] = checkers_move.to;

  auto elem = _board.at(i).at(j);
  _board.at(ii).at(jj) = elem;
  _board[i][j] = std::nullopt;
}

CheckersGame::CheckersGame(PlayerColor current_player,
                           CheckersBoard board,
                           Direction direction)
    : _current_player(current_player), _board(board), _direction(direction){};

std::vector<std::pair<int, int>> CheckersGame::get_positions() {
  std::vector<std::pair<int, int>> positions;
  for (int i = 0; i < _board.size(); ++i) {
    for (int j = 0; j < _board[i].size(); ++j) {
      auto elem = _board[i][j];
      if (elem.has_value() && elem.value().color == _current_player) {
        positions.push_back({i, j});
      }
    }
  }
  return positions;
};

std::vector<std::shared_ptr<Move>> CheckersGame::get_moves() {
  std::vector<std::shared_ptr<Move>> vec;

  return vec;
};

CheckersBoard CheckersGame::get_board() {
  return _board;
}
