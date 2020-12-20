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
  std::vector<std::shared_ptr<Move>> moves;
  auto positions = get_positions();
  auto delta_i = _direction == Direction::Up ? -1 : 1;

  for (const auto& from : positions) {
    const auto [i, j] = from;
    std::cout << "Got from-position " << i << ", " << j << std::endl;
    for (auto delta_j : {-1, 1}) {
      auto ii = i + delta_i;
      auto jj = j + delta_j;

      if (_board[ii][jj].has_value() &&
          _board[ii][jj].value().color != _current_player) {
        std::cout << "Got to-position " << ii << ", " << jj << std::endl;
        auto to = std::make_pair(i + 2 * delta_i, j + 2 * delta_j);
        moves.push_back(std::make_shared<CheckersMove>(from, to));
      }
    }
  }

  return moves;
};

CheckersBoard CheckersGame::get_board() {
  return _board;
}
