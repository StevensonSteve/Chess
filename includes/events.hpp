#pragma once
#include <SFML/Graphics.hpp>
#include "figures.hpp"
#include "board.hpp"
#include "history.hpp"

namespace Events {
    void process(
        sf::RenderWindow& window, 
        ChessBoard& chessboard, 
        FigurePosition& figurePosition, 
        Side& currentTurn, 
        std::vector<Move>& moveHistory
    );
}