#include "events.hpp"
#include <iostream>

void Events::process(sf::RenderWindow& window, ChessBoard& chessboard, FigurePosition& activeFigurePosition) {
    sf::Event event;

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
            if (!piece.isEmpty()) {
                activeFigurePosition.x = clickX;
                activeFigurePosition.y = clickY;
            }
        } else {
            bool canMove = Board::canMovePawn(
                chessboard,
                activeFigurePosition.x, activeFigurePosition.y,
                clickX, clickY
            );

            std::cout << "canMove: " << canMove << std::endl;

            if (canMove) {
                chessboard[clickX][clickY] = chessboard[activeFigurePosition.x][activeFigurePosition.y];
                chessboard[activeFigurePosition.x][activeFigurePosition.y] = {};
            }

            activeFigurePosition.reset();
        }
    }
}
