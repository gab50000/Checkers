#include <checkers/checkers.hpp>
#include <iostream>

const int BOARD_SIZE = 8;

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
      int i_enemy = i + delta_i;
      int j_enemy = j + delta_j;
      int i_final = i + 2 * delta_i;
      int j_final = j + 2 * delta_j;

      if (_board[i_enemy][j_enemy].has_value() &&
          _board[i_enemy][j_enemy].value().color != _current_player &&
          0 <= i_final && i_final < BOARD_SIZE && 0 < j_final &&
          j_final < BOARD_SIZE) {
        auto to = std::make_pair(i_final, j_final);
        moves.push_back(std::make_shared<CheckersMove>(from, to));
      }
    }
  }

  return moves;
};

CheckersBoard CheckersGame::get_board() {
  return _board;
}
