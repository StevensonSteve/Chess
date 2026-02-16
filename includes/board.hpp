#pragma once

#include <string>
#include <array>
#include "constants.hpp"

using ChessBoard = std::array<std::array<std::string, BOARD_SIZE>, BOARD_SIZE>;

namespace Board {
    // Инициализация начальной позиции
    void init(ChessBoard &chessboard);
    
    // В будущем здесь будут:
    // bool move(ChessBoard &chessboard, int fromX, int fromY, int toX, int toY);
}
