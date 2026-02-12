#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 8;
const float SQUARE_SIZE = 100.f;
using ChessBoard = array<array<string, BOARD_SIZE>, BOARD_SIZE>;

void drawChessboard(sf::RenderWindow& window) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            sf::RectangleShape rect(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            rect.setPosition(i * SQUARE_SIZE, j * SQUARE_SIZE);

            if ((i + j) % 2 == 0) {
                rect.setFillColor(sf::Color::White);
            } else {
                rect.setFillColor(sf::Color(100, 100, 100));
            }  

            window.draw(rect);
        }
    }
}

/*
* King (Король)
* Queen (Ферзь/Королева)
* Rook (Ладья)
* Bishop (Слон)
* Knight (Конь)
* Pawn (Пешка)
*/
void setFigures(ChessBoard &chessboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 0 && i == 4) {
                chessboard[i][j] = "bKing";
            } else if (j == 0 && i == 3) {
                chessboard[i][j] = "bQueen";
            } else if (j == 0 && (i == 0 || i == 7)) {
                chessboard[i][j] = "bRook";
            } else if (j == 0 && (i == 2 || i == 5)) {
                chessboard[i][j] = "bBishop";
            } else if (j == 0 && (i == 1 || i == 6)) {
                chessboard[i][j] = "bKnight";
            } else if (j == 1) {
                chessboard[i][j] = "bPawn";
            } else if (j == 7 && i == 4) {
                chessboard[i][j] = "wKing";
            } else if (j == 7 && i == 3) {
                chessboard[i][j] = "wQueen";
            } else if (j == 7 && (i == 0 || i == 7)) {
                chessboard[i][j] = "wRook";
            } else if (j == 7 && (i == 2 || i == 5)) {
                chessboard[i][j] = "wBishop";
            } else if (j == 7 && (i == 1 || i == 6)) {
                chessboard[i][j] = "wKnight";
            } else if (j == 6) {
                chessboard[i][j] = "wPawn";
            }

        }
    }    
}

sf::ConvexShape drawKnight(int x, int y, sf::Color color) {
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

sf::ConvexShape drawRook(int x, int y, sf::Color color) {
    sf::ConvexShape RookFigure;
    RookFigure.setPointCount(4);

    RookFigure.setPoint(0, sf::Vector2f(25.f, 25.f));
    RookFigure.setPoint(1, sf::Vector2f(75.f, 25.f));
    RookFigure.setPoint(2, sf::Vector2f(75.f, 75.f));
    RookFigure.setPoint(3, sf::Vector2f(25.f, 75.f));

    RookFigure.setFillColor(color);
    RookFigure.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return RookFigure;
}

sf::ConvexShape drawBishop(int x, int y, sf::Color color) {
    sf::ConvexShape BishopFigure;
    BishopFigure.setPointCount(4);

    BishopFigure.setPoint(0, sf::Vector2f(50.f, 25.f));
    BishopFigure.setPoint(1, sf::Vector2f(75.f, 50.f));
    BishopFigure.setPoint(2, sf::Vector2f(50.f, 75.f));
    BishopFigure.setPoint(3, sf::Vector2f(25.f, 50.f));

    BishopFigure.setFillColor(color);
    BishopFigure.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return BishopFigure;
}

sf::ConvexShape drawKing(int x, int y, sf::Color color) {
    sf::ConvexShape kingFigure;
    kingFigure.setPointCount(3);

    kingFigure.setPoint(0, sf::Vector2f(50.f, 75.f));
    kingFigure.setPoint(1, sf::Vector2f(25.f, 25.f));
    kingFigure.setPoint(2, sf::Vector2f(75.f, 25.f));

    kingFigure.setFillColor(color);
    kingFigure.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return kingFigure;
}

sf::ConvexShape drawQueen(int x, int y, sf::Color color) {
    sf::ConvexShape queenFigure;
    queenFigure.setPointCount(3);

    queenFigure.setPoint(0, sf::Vector2f(50.f, 25.f));
    queenFigure.setPoint(1, sf::Vector2f(75.f, 75.f));
    queenFigure.setPoint(2, sf::Vector2f(25.f, 75.f));

    queenFigure.setFillColor(color);
    queenFigure.setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE);

    return queenFigure;
}

sf::CircleShape drawPawn(int x, int y, sf::Color color) {
    sf::CircleShape circle(SQUARE_SIZE / 4); 
    circle.setPosition(x * SQUARE_SIZE + SQUARE_SIZE / 4, y * SQUARE_SIZE + SQUARE_SIZE / 4);
    circle.setFillColor(color);

    return circle;
}

void eventProcess(sf::RenderWindow& window, ChessBoard &chessboard) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
            window.close();
    }


    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / (int)SQUARE_SIZE;
        int y = event.mouseButton.y / (int)SQUARE_SIZE;

        if (event.mouseButton.button == sf::Mouse::Left) {
            // chessboard[x][y] = 'R';
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            // chessboard[x][y] = (x + y) % 2 == 0 ? 'W' : 'B';
        }
    }     
}


void drawCircle(sf::RenderWindow& window, ChessBoard &chessboard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (chessboard[i][j] == "bPawn") {
                window.draw(drawPawn(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wPawn") {
                window.draw(drawPawn(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "wKing") {
                window.draw(drawKing(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bKing") {
                window.draw(drawKing(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wQueen") {
                window.draw(drawQueen(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bQueen") {
                window.draw(drawQueen(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wRook") {
                window.draw(drawRook(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bRook") {
                window.draw(drawRook(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wBishop") {
                window.draw(drawBishop(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bBishop") {
                window.draw(drawBishop(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wKnight") {
                window.draw(drawKnight(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bKnight") {
                window.draw(drawKnight(i, j, sf::Color::Black));
            }                                                                            
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    ChessBoard chessboard;

    setFigures(chessboard);
    
    while (window.isOpen()) {
        
        eventProcess(window, chessboard);
        
        window.clear();
        
        drawChessboard(window);
        drawCircle(window, chessboard);

        window.display();

    }

    return 0;
}
