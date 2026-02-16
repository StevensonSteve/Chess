#include <iostream> // это отладочное подключение удалить

#include "figures.hpp"

FiguresShapes Figures::init() {
    FiguresShapes figures;

    figures["wKing"] = Figures::createKing(sf::Color::Blue);
    figures["bKing"] = Figures::createKing(sf::Color::Black);
    figures["wQueen"] = Figures::createQueen(sf::Color::Blue);
    figures["bQueen"] = Figures::createQueen(sf::Color::Black);
    figures["wRook"] = Figures::createRook(sf::Color::Blue);
    figures["bRook"] = Figures::createRook(sf::Color::Black);
    figures["wBishop"] = Figures::createBishop(sf::Color::Blue);
    figures["bBishop"] = Figures::createBishop(sf::Color::Black);
    figures["wKnight"] = Figures::createKnight(sf::Color::Blue);
    figures["bKnight"] = Figures::createKnight(sf::Color::Black);
    figures["wPawn"] = Figures::createPawn(sf::Color::Blue);
    figures["bPawn"] = Figures::createPawn(sf::Color::Black);

    return figures;
} 

sf::ConvexShape Figures::createKing(sf::Color color) {
    sf::ConvexShape king;
    king.setPointCount(3);

    std::cout << 12;
    king.setPoint(0, sf::Vector2f(50.f, 75.f));
    king.setPoint(1, sf::Vector2f(25.f, 25.f));
    king.setPoint(2, sf::Vector2f(75.f, 25.f));
    
    king.setFillColor(color);
    
    return king;
}

sf::ConvexShape Figures::createQueen(sf::Color color) {
    sf::ConvexShape queen;
    queen.setPointCount(3);

    queen.setPoint(0, sf::Vector2f(50.f, 25.f));
    queen.setPoint(1, sf::Vector2f(75.f, 75.f));
    queen.setPoint(2, sf::Vector2f(25.f, 75.f));

    queen.setFillColor(color);

    return queen;
}

sf::ConvexShape Figures::createRook(sf::Color color) {
    sf::ConvexShape rook;
    rook.setPointCount(4);

    rook.setPoint(0, sf::Vector2f(25.f, 25.f));
    rook.setPoint(1, sf::Vector2f(75.f, 25.f));
    rook.setPoint(2, sf::Vector2f(75.f, 75.f));
    rook.setPoint(3, sf::Vector2f(25.f, 75.f));

    rook.setFillColor(color);
    
    return rook;
}

sf::ConvexShape Figures::createBishop(sf::Color color) {
    sf::ConvexShape bishop;
    bishop.setPointCount(4);

    bishop.setPoint(0, sf::Vector2f(50.f, 25.f));
    bishop.setPoint(1, sf::Vector2f(75.f, 50.f));
    bishop.setPoint(2, sf::Vector2f(50.f, 75.f));
    bishop.setPoint(3, sf::Vector2f(25.f, 50.f));

    bishop.setFillColor(color);
    
    return bishop;
}

sf::ConvexShape Figures::createKnight(sf::Color color) {
    sf::ConvexShape knight;
    knight.setPointCount(5);

    knight.setPoint(0, sf::Vector2f(35.f, 80.f));
    knight.setPoint(1, sf::Vector2f(65.f, 80.f));
    knight.setPoint(2, sf::Vector2f(65.f, 20.f));
    knight.setPoint(3, sf::Vector2f(40.f, 20.f));
    knight.setPoint(4, sf::Vector2f(25.f, 40.f));

    knight.setFillColor(color);
    return knight;
}

sf::ConvexShape Figures::createPawn(sf::Color color) {
    sf::ConvexShape pawn;
    pawn.setPointCount(8);

    pawn.setPoint(0, sf::Vector2f(40.f, 20.f));
    pawn.setPoint(1, sf::Vector2f(60.f, 20.f));
    pawn.setPoint(2, sf::Vector2f(80.f, 40.f));
    pawn.setPoint(3, sf::Vector2f(80.f, 60.f));
    pawn.setPoint(4, sf::Vector2f(60.f, 80.f));
    pawn.setPoint(5, sf::Vector2f(40.f, 80.f));
    pawn.setPoint(6, sf::Vector2f(20.f, 60.f));
    pawn.setPoint(7, sf::Vector2f(20.f, 40.f));

    pawn.setFillColor(color);

    return pawn;
}