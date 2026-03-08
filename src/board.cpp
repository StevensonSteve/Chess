#include "board.hpp"
#include <cmath>
#include <iostream>

void Board::init(ChessBoard &chessboard) {
    chessboard[0][0] = {PieceType::Rook,   Side::Black};
    chessboard[1][0] = {PieceType::Knight, Side::Black};
    chessboard[2][0] = {PieceType::Bishop, Side::Black};
    chessboard[3][0] = {PieceType::Queen,  Side::Black};
    chessboard[4][0] = {PieceType::King,   Side::Black};
    chessboard[5][0] = {PieceType::Bishop, Side::Black};
    chessboard[6][0] = {PieceType::Knight, Side::Black};
    chessboard[7][0] = {PieceType::Rook,   Side::Black};

    for (int i = 0; i < BOARD_SIZE; i++)
        chessboard[i][1] = {PieceType::Pawn, Side::Black};

    chessboard[0][7] = {PieceType::Rook,   Side::White};
    chessboard[1][7] = {PieceType::Knight, Side::White};
    chessboard[2][7] = {PieceType::Bishop, Side::White};
    chessboard[3][7] = {PieceType::Queen,  Side::White};
    chessboard[4][7] = {PieceType::King,   Side::White};
    chessboard[5][7] = {PieceType::Bishop, Side::White};
    chessboard[6][7] = {PieceType::Knight, Side::White};
    chessboard[7][7] = {PieceType::Rook,   Side::White};

    for (int i = 0; i < BOARD_SIZE; i++)
        chessboard[i][6] = {PieceType::Pawn, Side::White};
}

bool Board::canKingMove(int fromX, int fromY, int toX ,int toY) {
    return ((fromX - toX) * (fromX - toX) > 1) || ((fromY - toY) * (fromY - toY) > 1);
}

bool Board::canRookMove(int fromX, int fromY, int toX ,int toY) {
    return fromX == toX || fromY == toY;
}

bool Board::canBishopMove(int fromX, int fromY, int toX ,int toY) {
    int Y3, X3;
    X3 = fromX - toX;
    Y3 = fromY - toY;
    return std::abs(Y3) - std::abs(X3) == 0;
}

bool Board::canMovePawn(const ChessBoard &chessboard, int fromX, int fromY, int toX, int toY) {
    const Piece& pawn = chessboard[fromX][fromY];
    if (pawn.type != PieceType::Pawn) return false;

    // White moves up (y decreases), Black moves down (y increases)
    const int diraction = (pawn.side == Side::White) ? -1 : 1;
    const int startY = (pawn.side == Side::White) ? 6 : 1;
    const Piece& target = chessboard[toX][toY];

    if (toX == fromX && toY == fromY + diraction && target.isEmpty()) {
        return true;
    }

    if (toX == fromX && fromY == startY && toY == fromY + 2 * diraction) {
        const Piece& intermediate = chessboard[fromX][fromY + diraction];
        if (intermediate.isEmpty() && target.isEmpty()) {
            return true;
        }
    }

    if (std::abs(toX - fromX) == 1 && toY == fromY + diraction && target.isEnemy(pawn.side)) {
        return true;
    }

    return false;
}
