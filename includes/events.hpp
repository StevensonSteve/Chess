#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"

namespace Events {
    void process(sf::RenderWindow& window, ChessBoard &chessboard);
}