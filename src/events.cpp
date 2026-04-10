#include <iostream>

#include "events.hpp"
#include "history.hpp"

void Events::process(
    sf::RenderWindow& window, 
    ChessBoard& chessboard, 
    FigurePosition& activeFigurePosition, 
    Side& currentTurn, 
    std::vector<Move>& moveHistory
) {
    sf::Event event;
    Move currentMove;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type != sf::Event::MouseButtonPressed || event.mouseButton.button != sf::Mouse::Left) {
            continue;
        }

        int clickX = event.mouseButton.x / static_cast<int>(SQUARE_SIZE);
        int clickY = event.mouseButton.y / static_cast<int>(SQUARE_SIZE);

        if (clickX < 0 || clickX >= BOARD_SIZE || clickY < 0 || clickY >= BOARD_SIZE) {
            continue;
        }

        if (!activeFigurePosition.isValid()) {
            const Piece& piece = chessboard[clickX][clickY];
            if (!piece.isEmpty() && piece.side == currentTurn) {
                activeFigurePosition.x = clickX;
                activeFigurePosition.y = clickY;
            }
            currentMove.piece = piece;
        } else {
            bool canMoveKing = Board::canMoveKing(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            bool canMovePawn = Board::canMovePawn(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            bool canMoveRook = Board::canMoveRook(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            bool canMoveBishop = Board::canMoveBishop(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );


            bool canMoveQueen = Board::canMoveQueen(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            bool canMoveKnight = Board::canMoveKnight(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            if (canMoveKing || canMovePawn || canMoveRook || canMoveBishop || canMoveQueen || canMoveKnight) {
                currentMove.from.x = activeFigurePosition.x;
                currentMove.from.y = activeFigurePosition.y;
                currentMove.to.x = clickX;
                currentMove.to.y = clickY;
                chessboard[clickX][clickY] = chessboard[activeFigurePosition.x][activeFigurePosition.y];
                chessboard[activeFigurePosition.x][activeFigurePosition.y] = {};
                currentTurn = (currentTurn == Side::White) ? Side::Black : Side::White;
                // std::cout << "from: (" << currentMove.from.x + 1 << ";" << currentMove.from.y + 1 << ") | " 
                // << "to: (" << currentMove.to.x + 1 << ";" << currentMove.to.y + 1 << ")" << std::endl;
                moveHistory.push_back(currentMove);
            }
            for (const auto& move : moveHistory) {
                std::cout << " From: " << move.from.x << "," << move.from.y 
                        << " To: " << move.to.x << "," << move.to.y 
                        << std::endl;
            }

            activeFigurePosition.reset();
        }
    }
}
