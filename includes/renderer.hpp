#pragma once
#include <SFML/Graphics.hpp>

#include "board.hpp"
#include "figures.hpp"

namespace Renderer {
    void drawBoard(sf::RenderWindow& window);
    void drawFigures(sf::RenderWindow& window, ChessBoard &chessboard, FiguresShapes &figuresShapes);
    void highlightActiveCell(sf::RenderWindow& window,int x,int y);
}
