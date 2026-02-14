#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "figures.hpp"

sf::ConvexShape Figures::drawKnight(int x, int y, sf::Color color) {
    sf::ConvexShape KnightFigure;
    KnightFigure.setPointCount(4);

    KnightFigure.setPoint(0, sf::Vector2f(35.f, 20.f));
    KnightFigure.setPoint(1, sf::Vector2f(65.f, 20.f));
    KnightFigure.setPoint(2, sf::Vector2f(65.f, 80.f));
    KnightFigure.setPoint(3, sf::Vector2f(35.f, 80.f));

    KnightFigure.setFillColor(color);
    KnightFigure.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return KnightFigure;
}
