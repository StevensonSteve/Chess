#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <utility>

enum class Side { None, White, Black };
enum class PieceType { None, King, Queen, Rook, Bishop, Knight, Pawn };

struct Piece {
    PieceType type = PieceType::None;
    Side side = Side::None;

    bool isEmpty() const { return type == PieceType::None; }
    bool isEnemy(Side other) const { return side != Side::None && side != other; }
};

using FiguresShapes = std::map<std::pair<Side, PieceType>, sf::ConvexShape>;

struct FigurePosition {
    int x = -1;
    int y = -1;

    bool isValid() const { return x >= 0 && y >= 0; }
    void reset() { x = -1; y = -1; }
};

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
