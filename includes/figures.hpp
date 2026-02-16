#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

using FiguresShapes = std::map <std::string, sf::ConvexShape>;

/*
* King (Король)
* Queen (Ферзь/Королева)
* Rook (Ладья)
* Bishop (Слон)
* Knight (Конь)
* Pawn (Пешка)
*/
namespace Figures {
    FiguresShapes init();

    sf::ConvexShape createKing(sf::Color color);
    sf::ConvexShape createQueen(sf::Color color);
    sf::ConvexShape createRook(sf::Color color);
    sf::ConvexShape createBishop(sf::Color color);
    sf::ConvexShape createKnight(sf::Color color);
    sf::ConvexShape createPawn(sf::Color color);
}
