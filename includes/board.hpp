#pragma once

#include <array>
#include "constants.hpp"
#include "figures.hpp"

using ChessBoard = std::array<std::array<Piece, BOARD_SIZE>, BOARD_SIZE>;

namespace Board {
    void init(ChessBoard &chessboard);
    bool canKingMove(int fromX, int fromY, int toX ,int toY);
    bool canRookMove(int fromX, int fromY, int toX ,int toY);
    bool canBishopMove(int fromX, int fromY, int toX ,int toY);
    bool canMovePawn(const ChessBoard &chessboard, int fromX, int fromY, int toX, int toY);
}
