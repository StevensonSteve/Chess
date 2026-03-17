#include "figures.hpp"

namespace {
    sf::Color renderColor(Side side) {
        return (side == Side::White) ? sf::Color::Blue : sf::Color::Black;
    }
}

FiguresShapes Figures::init() {
    FiguresShapes figures;

    for (Side side : {Side::White, Side::Black}) {
        sf::Color color = renderColor(side);
        figures[{side, PieceType::King}]   = createKing(color);
        figures[{side, PieceType::Queen}]  = createQueen(color);
        figures[{side, PieceType::Rook}]   = createRook(color);
        figures[{side, PieceType::Bishop}] = createBishop(color);
        figures[{side, PieceType::Knight}] = createKnight(color);
        figures[{side, PieceType::Pawn}]   = createPawn(color);
    }

    return figures;
}

sf::ConvexShape Figures::createKing(sf::Color color) {
    sf::ConvexShape king;

    king.setPointCount(22); 

    king.setPoint(0, sf::Vector2f(65.f, 25.f));
    king.setPoint(1, sf::Vector2f(65.f, 35.f));
    king.setPoint(2, sf::Vector2f(55.f, 45.f));
    king.setPoint(3, sf::Vector2f(75.f, 80.f));
    king.setPoint(4, sf::Vector2f(75.f, 90.f));

    king.setPoint(5, sf::Vector2f(25.f, 90.f));
    king.setPoint(6, sf::Vector2f(25.f, 80.f));
    king.setPoint(7, sf::Vector2f(45.f, 45.f));
    king.setPoint(8, sf::Vector2f(35.f, 35.f));
    king.setPoint(9, sf::Vector2f(35.f, 25.f));
    king.setPoint(10, sf::Vector2f(47.f, 25.f));
    king.setPoint(11, sf::Vector2f(47.f, 20.f));
    king.setPoint(12, sf::Vector2f(42.f, 20.f));
    king.setPoint(13, sf::Vector2f(42.f, 15.f));
    king.setPoint(14, sf::Vector2f(47.f, 15.f));
    king.setPoint(15, sf::Vector2f(47.f, 10.f));
    king.setPoint(16, sf::Vector2f(53.f, 10.f));
    king.setPoint(17, sf::Vector2f(53.f, 15.f));
    king.setPoint(18, sf::Vector2f(58.f, 15.f));
    king.setPoint(19, sf::Vector2f(58.f, 20.f));
    king.setPoint(20, sf::Vector2f(53.f, 20.f));
    king.setPoint(21, sf::Vector2f(53.f, 25.f));

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
    rook.setPointCount(16);

    rook.setPoint(0,  sf::Vector2f(30.f, 20.f));
    rook.setPoint(1,  sf::Vector2f(38.f, 20.f));
    rook.setPoint(2,  sf::Vector2f(38.f, 30.f));

    rook.setPoint(3,  sf::Vector2f(46.f, 30.f));
    rook.setPoint(4,  sf::Vector2f(46.f, 20.f));
    rook.setPoint(5,  sf::Vector2f(54.f, 20.f));
    rook.setPoint(6,  sf::Vector2f(54.f, 30.f));

    rook.setPoint(7,  sf::Vector2f(62.f, 30.f));
    rook.setPoint(8,  sf::Vector2f(62.f, 20.f));
    rook.setPoint(9,  sf::Vector2f(70.f, 20.f));

    rook.setPoint(10, sf::Vector2f(70.f, 70.f));
    rook.setPoint(11, sf::Vector2f(75.f, 70.f));
    rook.setPoint(12, sf::Vector2f(75.f, 80.f));

    rook.setPoint(13, sf::Vector2f(25.f, 80.f));
    rook.setPoint(14, sf::Vector2f(25.f, 70.f));
    rook.setPoint(15, sf::Vector2f(30.f, 70.f));

    rook.setFillColor(color);
    
    return rook;
}

sf::ConvexShape Figures::createBishop(sf::Color color) {
    sf::ConvexShape bishop;
    bishop.setPointCount(10); 

    bishop.setPoint(0, sf::Vector2f(50.f, 10.f));
    bishop.setPoint(1, sf::Vector2f(65.f, 35.f));
    bishop.setPoint(2, sf::Vector2f(55.f, 45.f));
    bishop.setPoint(3, sf::Vector2f(75.f, 80.f));
    bishop.setPoint(4, sf::Vector2f(75.f, 90.f));

    bishop.setPoint(5, sf::Vector2f(25.f, 90.f));
    bishop.setPoint(6, sf::Vector2f(25.f, 80.f));
    bishop.setPoint(7, sf::Vector2f(45.f, 45.f));
    bishop.setPoint(8, sf::Vector2f(35.f, 35.f));
    bishop.setPoint(9, sf::Vector2f(50.f, 10.f));

    bishop.setFillColor(color);
    return bishop;
}

sf::ConvexShape Figures::createKnight(sf::Color color) {
    sf::ConvexShape knight;
    knight.setPointCount(15); 

    knight.setPoint(0,  sf::Vector2f(25.f, 90.f));
    knight.setPoint(1,  sf::Vector2f(75.f, 90.f));
    knight.setPoint(2,  sf::Vector2f(75.f, 82.f));

    knight.setPoint(3,  sf::Vector2f(65.f, 70.f));
    knight.setPoint(4,  sf::Vector2f(68.f, 40.f));
    knight.setPoint(5,  sf::Vector2f(60.f, 15.f));
    
    knight.setPoint(6,  sf::Vector2f(50.f, 25.f));
    knight.setPoint(7,  sf::Vector2f(45.f, 18.f));
    knight.setPoint(8,  sf::Vector2f(35.f, 28.f));
    knight.setPoint(9,  sf::Vector2f(15.f, 45.f));
    knight.setPoint(10, sf::Vector2f(20.f, 55.f));
    knight.setPoint(11, sf::Vector2f(35.f, 52.f));

    knight.setPoint(12, sf::Vector2f(45.f, 65.f));
    knight.setPoint(13, sf::Vector2f(35.f, 82.f));
    knight.setPoint(14, sf::Vector2f(25.f, 82.f));

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
