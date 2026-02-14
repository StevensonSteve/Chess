#pragma once

#include <SFML/Graphics.hpp>

/*
* King (Король)
* Queen (Ферзь/Королева)
* Rook (Ладья)
* Bishop (Слон)
* Knight (Конь)
* Pawn (Пешка)
*/
namespace Figures {
    sf::ConvexShape createKing(int x, int y, sf::Color color);
    sf::ConvexShape createQueen(int x, int y, sf::Color color);
    sf::ConvexShape createRook(int x, int y, sf::Color color);
    sf::ConvexShape createBishop(int x, int y, sf::Color color);
    sf::ConvexShape createKnight(int x, int y, sf::Color color);
    sf::CircleShape createPawn(int x, int y, sf::Color color);
}
