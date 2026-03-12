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

bool straightLineMove(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& type = chessboard[fromX][fromY];
    const Piece& target = chessboard[toX][toY];

    if (fromX != toX && fromY != toY) {
        return false;
    }

    if (!target.isEmpty() && !target.isEnemy(type.side)) {
        return false;
    }

    if (toX - fromX == 0) {
        int delY = (toY > fromY) ? 1 : -1;
        int curY = fromY + delY;

        while (curY != toY) {
            if (!chessboard[fromX][curY].isEmpty()) {
                return false;
            }
            curY += delY;
        }
    }

    if (toY - fromY == 0) {
        int delX = (toX > fromX) ? 1 : -1;
        int curX = fromX + delX;

        while (curX != toX) {
            if (!chessboard[curX][fromY].isEmpty()) {
                return false;
            }
            curX += delX;
        }
    }

    return true;
}

bool diagonalMove(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& bishop = chessboard[fromX][fromY];
    const Piece& target = chessboard[toX][toY];

    if (std::abs(fromX - toX) != std::abs(fromY - toY)) {
        return false;
    }

    if (!target.isEmpty() && !target.isEnemy(bishop.side)) {
        return false;
    }

    int delX = (toX > fromX) ? 1 : -1;
    int delY = (toY > fromY) ? 1 : -1;

    int curX = fromX + delX;
    int curY = fromY + delY;

    while (curX != toX && curY != toY) {
        if (!chessboard[curX][curY].isEmpty()) {
            return false;
        }
        curX += delX;
        curY += delY;
    }

    return true;
}

bool Board::canMoveKing(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& king = chessboard[fromX][fromY];

    if (king.type != PieceType::King) {
        return false;
    }

    const Piece& target = chessboard[toX][toY];

    return (((fromX - toX) * (fromX - toX) == 1) || ((fromY - toY) * (fromY - toY) == 1))
        && (target.isEmpty() || target.isEnemy(king.side))
        && !(target.type == PieceType::King);
}

bool Board::canMoveQueen(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& queen = chessboard[fromX][fromY];

    if (queen.type != PieceType::Queen) {
        return false;
    }

    return straightLineMove(chessboard, fromX, fromY, toX , toY)
        || diagonalMove(chessboard, fromX, fromY, toX, toY);
}

bool Board::canMoveRook(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& rook = chessboard[fromX][fromY];

    if (rook.type != PieceType::Rook) {
        return false;
    }

    return straightLineMove(chessboard, fromX, fromY, toX , toY);
}

bool Board::canMoveBishop(const ChessBoard &chessboard, int fromX, int fromY, int toX, int toY) {
    const Piece& bishop = chessboard[fromX][fromY];

    if (bishop.type != PieceType::Bishop) {
        return false;
    }

    return diagonalMove(chessboard, fromX, fromY, toX, toY);
}

bool Board::canMoveKnight(const ChessBoard &chessboard, int fromX, int fromY, int toX ,int toY) {
    const Piece& knight = chessboard[fromX][fromY];

    if (knight.type != PieceType::Knight) {
        return false;
    }

    const Piece& target = chessboard[toX][toY];

    return ((std::abs(fromY - toY) == 2 &&  std::abs(fromX - toX) == 1) || (std::abs(fromY - toY) == 1 && std::abs(fromX - toX) == 2))
        && (target.isEmpty() || target.isEnemy(knight.side));
}

bool Board::canMovePawn(const ChessBoard &chessboard, int fromX, int fromY, int toX, int toY) {
    const Piece& pawn = chessboard[fromX][fromY];
    if (pawn.type != PieceType::Pawn) {
        return false;
    }

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
