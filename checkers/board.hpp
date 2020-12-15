#pragma once

#include <vector>

enum class BoardState { black_man, white_man, black_king, white_king, empty };

using CheckersBoard = std::vector<std::vector<BoardState>>;

CheckersBoard empty_board();