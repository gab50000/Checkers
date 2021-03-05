#include <checkers/checkers.hpp>
#include <iostream>

const int BOARD_SIZE = 8;

CheckersMove::CheckersMove(const std::pair<int, int>& from,
                           const std::pair<int, int>& to)
    : from(from), to(to){};

bool CheckersMove::operator==(const CheckersMove& other) {
  return (from == other.from) && (to == other.to);
}

CheckersGame CheckersGame::make_move(const CheckersMove& checkers_move) {
  auto [i, j] = checkers_move.from;
  auto [ii, jj] = checkers_move.to;
  auto new_board = _board;

  auto elem = _board[i][j];
  new_board[ii][jj] = elem;
  new_board[i][j] = std::nullopt;
  auto new_color = _current_player == PlayerColor::black ? PlayerColor::white
                                                         : PlayerColor::black;
  auto new_direction =
      _direction == Direction::Up ? Direction::Down : Direction::Up;

  auto new_game = CheckersGame(new_color, new_board, new_direction);
  return new_game;
}

CheckersGame::CheckersGame(const PlayerColor& current_player,
                           const CheckersBoard& board,
                           const Direction& direction)
    : _current_player(current_player), _board(board), _direction(direction){};

std::ostream& operator<<(std::ostream& os, const CheckersGame& game) {
  for (const auto& row : game._board) {
    for (const auto val : row) {
      if (val.has_value()) {
        os << val.value();
      } else {
        os << " ";
      }
    }
    os << "\n";
  }
  return os;
}

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

std::vector<CheckersMove> CheckersGame::get_moves() {
  std::vector<CheckersMove> moves;
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
        moves.push_back(CheckersMove(from, to));
      }
    }
  }
  return moves;
};

std::vector<int> CheckersGame::evaluate_moves(
    const std::vector<CheckersMove>& moves) {
  for (const auto& mv : moves) {
    make_move(mv);
  }
  return {};
}

CheckersBoard CheckersGame::get_board() {
  return _board;
}
