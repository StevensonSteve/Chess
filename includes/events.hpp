#pragma once
#include <SFML/Graphics.hpp>
#include "figures.hpp"
#include "board.hpp"

namespace Events {
    void process(sf::RenderWindow& window, ChessBoard& chessboard, FigurePosition& figurePosition, Side& currentTurn);
}