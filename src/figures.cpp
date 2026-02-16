#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.hpp"
#include "figures.hpp"

sf::ConvexShape Figures::createKing(int x, int y, sf::Color color) {
    sf::ConvexShape king;
    king.setPointCount(3);

    std::cout << 12;
    king.setPoint(0, sf::Vector2f(50.f, 75.f));
    king.setPoint(1, sf::Vector2f(25.f, 25.f));
    king.setPoint(2, sf::Vector2f(75.f, 25.f));
    
    king.setFillColor(color);
    // king.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);
    
    return king;
}

sf::ConvexShape Figures::createQueen(int x, int y, sf::Color color) {
    sf::ConvexShape queen;
    queen.setPointCount(3);

    queen.setPoint(0, sf::Vector2f(50.f, 25.f));
    queen.setPoint(1, sf::Vector2f(75.f, 75.f));
    queen.setPoint(2, sf::Vector2f(25.f, 75.f));

    queen.setFillColor(color);
    // queen.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return queen;
}

sf::ConvexShape Figures::createRook(int x, int y, sf::Color color) {
    sf::ConvexShape rook;
    rook.setPointCount(4);

    rook.setPoint(0, sf::Vector2f(25.f, 25.f));
    rook.setPoint(1, sf::Vector2f(75.f, 25.f));
    rook.setPoint(2, sf::Vector2f(75.f, 75.f));
    rook.setPoint(3, sf::Vector2f(25.f, 75.f));

    rook.setFillColor(color);
    // rook.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);
    
    return rook;
}

sf::ConvexShape Figures::createBishop(int x, int y, sf::Color color) {
    sf::ConvexShape bishop;
    bishop.setPointCount(4);

    bishop.setPoint(0, sf::Vector2f(50.f, 25.f));
    bishop.setPoint(1, sf::Vector2f(75.f, 50.f));
    bishop.setPoint(2, sf::Vector2f(50.f, 75.f));
    bishop.setPoint(3, sf::Vector2f(25.f, 50.f));

    bishop.setFillColor(color);
    // bishop.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);
    
    return bishop;
}

sf::ConvexShape Figures::createKnight(int x, int y, sf::Color color) {
    sf::ConvexShape knight;
    knight.setPointCount(4);

    knight.setPoint(0, sf::Vector2f(35.f, 20.f));
    knight.setPoint(1, sf::Vector2f(65.f, 20.f));
    knight.setPoint(2, sf::Vector2f(65.f, 80.f));
    knight.setPoint(3, sf::Vector2f(35.f, 80.f));

    knight.setFillColor(color);
    // knight.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return knight;
}

sf::CircleShape Figures::createPawn(int x, int y, sf::Color color) {
    sf::CircleShape pawn(SQUARE_SIZE / 4); 
    // pawn.setPosition(x * SQUARE_SIZE + SQUARE_SIZE / 4, y * SQUARE_SIZE + SQUARE_SIZE / 4);
    pawn.setFillColor(color);

    return pawn;
}