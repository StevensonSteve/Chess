#include "board.hpp"

void Board::init(ChessBoard &chessboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 0 && i == 4) {
                chessboard[i][j] = "bKing";
            } else if (j == 0 && i == 3) {
                chessboard[i][j] = "bQueen";
            } else if (j == 0 && (i == 0 || i == 7)) {
                chessboard[i][j] = "bRook";
            } else if (j == 0 && (i == 2 || i == 5)) {
                chessboard[i][j] = "bBishop";
            } else if (j == 0 && (i == 1 || i == 6)) {
                chessboard[i][j] = "bKnight";
            } else if (j == 1) {
                chessboard[i][j] = "bPawn";
            } else if (j == 7 && i == 4) {
                chessboard[i][j] = "wKing";
            } else if (j == 7 && i == 3) {
                chessboard[i][j] = "wQueen";
            } else if (j == 7 && (i == 0 || i == 7)) {
                chessboard[i][j] = "wRook";
            } else if (j == 7 && (i == 2 || i == 5)) {
                chessboard[i][j] = "wBishop";
            } else if (j == 7 && (i == 1 || i == 6)) {
                chessboard[i][j] = "wKnight";
            } else if (j == 6) {
                chessboard[i][j] = "wPawn";
            }
        }
    }    
}
