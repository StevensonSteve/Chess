#include "renderer.hpp"

void Renderer::drawBoard(sf::RenderWindow& window) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            sf::RectangleShape rect(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            rect.setPosition(i * SQUARE_SIZE, j * SQUARE_SIZE);

            if ((i + j) % 2 == 0) {
                rect.setFillColor(sf::Color::White);
            } else {
                rect.setFillColor(sf::Color(100, 100, 100));
            }  

            window.draw(rect);
        }
    }
}

void Renderer::highlightActiveCell(sf::RenderWindow& window, int x, int y) {
    sf::RectangleShape rect(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
    rect.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);
    rect.setFillColor(sf::Color::Red);

    window.draw(rect); 
}

void Renderer::drawFigures(sf::RenderWindow& window, ChessBoard &chessboard, FiguresShapes &figuresShapes) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            const Piece& piece = chessboard[i][j];

            if (!piece.isEmpty()) {
                auto key = std::make_pair(piece.side, piece.type);
                figuresShapes[key].setPosition(i * SQUARE_SIZE, j * SQUARE_SIZE);
                window.draw(figuresShapes[key]);
            }
        }
    }
}
