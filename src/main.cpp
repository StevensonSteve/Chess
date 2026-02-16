#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "constants.hpp"
#include "figures.hpp"

using namespace std;

// const int BOARD_SIZE = 8;
// const float SQUARE_SIZE = 100.f;
using ChessBoard = array<array<string, BOARD_SIZE>, BOARD_SIZE>;
using FiguresShapes = map <string, sf::ConvexShape>;

void createChessboard(sf::RenderWindow& window) {
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


void createCircle(sf::RenderWindow& window, ChessBoard &chessboard, figuresShapes) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (chessboard[i][j] == "bPawn") {
                figuresShapes["bPawn"].setPosition(x * SQUARE_SIZE, y * SQUARE_SIZE)
                window.draw(Figures::createPawn(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wPawn") {
                window.draw(Figures::createPawn(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "wKing") {
                window.draw(Figures::createKing(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bKing") {
                window.draw(Figures::createKing(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wQueen") {
                window.draw(Figures::createQueen(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bQueen") {
                window.draw(Figures::createQueen(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wRook") {
                window.draw(Figures::createRook(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bRook") {
                window.draw(Figures::createRook(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wBishop") {
                window.draw(Figures::createBishop(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bBishop") {
                window.draw(Figures::createBishop(i, j, sf::Color::Black));
            } else if (chessboard[i][j] == "wKnight") {
                window.draw(Figures::createKnight(i, j, sf::Color::Blue));
            } else if (chessboard[i][j] == "bKnight") {
                window.draw(Figures::createKnight(i, j, sf::Color::Black));
            }                                                                            
        }
    }
}

FiguresShapes slojno() {
    FiguresShapes figures;

    figures["wKing"] = Figures::createKing(i, j, sf::Color::Blue);
    figures["bKing"] = Figures::createKing(i, j, sf::Color::Black);
    figures["wQueen"] = Figures::createQueen(i, j, sf::Color::Blue);
    figures["bQueen"] = Figures::createQueen(i, j, sf::Color::Black);
    figures["wRook"] = Figures::createRook(i, j, sf::Color::Blue);
    figures["bRook"] = Figures::createRook(i, j, sf::Color::Black);
    figures["wBishop"] = Figures::createBishop(i, j, sf::Color::Blue);
    figures["bBishop"] = Figures::createBishop(i, j, sf::Color::Black);
    figures["wKnight"] = Figures::createKnight(i, j, sf::Color::Blue);
    figures["bKnight"] = Figures::createKnight(i, j, sf::Color::Black);
    figures["wPawn"] = Figures::createPawn(i, j, sf::Color::Blue);
    figures["bPawn"] = Figures::createPawn(i, j, sf::Color::Black);
    

} 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    ChessBoard chessboard;
    FiguresShapes figuresShapes;

    setFigures(chessboard);
    figuresShapes = slojno();
    
    
    while (window.isOpen()) {
        
        eventProcess(window, chessboard);
        
        window.clear();
        
        createChessboard(window);
        createCircle(window, chessboard);

        window.display();

    }

    return 0;
}
