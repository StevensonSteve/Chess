#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

const int BOARD_SIZE = 8;
const float SQUARE_SIZE = 100.f;
using ChessBoard = std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>;

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
            chessboard[x][y] = 'R';
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            chessboard[x][y] = (x + y) % 2 == 0 ? 'W' : 'B';
        }
    }     
}


void setFigures(sf::RenderWindow& window, ChessBoard &chessboard) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (chessboard[i][j] == 'R') {
                    sf::CircleShape circle(SQUARE_SIZE / 4); 
                    circle.setPosition(i * SQUARE_SIZE + SQUARE_SIZE / 4, j * SQUARE_SIZE + SQUARE_SIZE / 4);
                    circle.setFillColor(sf::Color::Red);
                    window.draw(circle);
                }
            }

        }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    ChessBoard chessboard;

    while (window.isOpen()) {

        eventProcess(window, chessboard);
    
        window.clear();

        drawChessboard(window);
        setFigures(window, chessboard);

        window.display();

    }

    return 0;
}
