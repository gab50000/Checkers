#include <checkers/checkers.hpp>
#include <iostream>

const int BOARD_SIZE = 8;

CheckersMove::CheckersMove(std::pair<int, int> from, std::pair<int, int> to)
    : from(from), to(to){};

bool CheckersMove::operator=(const CheckersMove& other) {
  return (from == other.from) && (to == other.to);
}

CheckersGame CheckersGame::make_move(CheckersMove& checkers_move) {
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

std::vector<std::shared_ptr<CheckersMove>> CheckersGame::get_moves() {
  std::vector<std::shared_ptr<CheckersMove>> moves;
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

std::vector<int> CheckersGame::evaluate_moves(
    const std::vector<std::shared_ptr<CheckersMove>>& moves) {
  for (auto& mv : moves) {
    auto checkers_move = static_cast<CheckersMove*>(mv.get());
    make_move(*checkers_move);
  }
}

CheckersBoard CheckersGame::get_board() {
  return _board;
}
