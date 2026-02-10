#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

const int BOARD_SIZE = 8;
const float SQUARE_SIZE = 100.f;
using ChessBoard = std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>;

char getSquareColor(int x, int y) {
    if ((x + y) % 2 == 0) {
        return 'W';
    } else {
        return 'B';
    }    
}

ChessBoard initChessboard() {
    ChessBoard chessboard;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessboard[i][j] = getSquareColor(i, j);
        }
    }

    return chessboard;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    float size = SQUARE_SIZE;
    ChessBoard chessboard;

    chessboard = initChessboard();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }


        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / (int)size;
                int y = event.mouseButton.y / (int)size;
                // cout << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y << "\n";
                chessboard[x][y] = 'R';
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                int x = event.mouseButton.x / (int)size;
                int y = event.mouseButton.y / (int)size;
                // cout << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y << "\n";
                chessboard[x][y] = getSquareColor(x, y);
            }
        }        

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {

                if (chessboard[i][j] == 'W' || chessboard[i][j] == 'B') {
                    sf::RectangleShape rect(sf::Vector2f(size, size));
                    rect.setPosition(i * size, j * size);
                    switch (chessboard[i][j]) {
                        case 'W':
                            rect.setFillColor(sf::Color::White);
                            break;
                        case 'B':
                        rect.setFillColor(sf::Color(100, 100, 100));
                            break;
                    // default:
                    //     std::cout << "This is a middle row (2-5)." << std::endl;
                    //     break;
                    }
                    window.draw(rect);
                } else {
                    sf::CircleShape circle(SQUARE_SIZE / 4); 
                    circle.setPosition(i * size + SQUARE_SIZE / 4, j * size + SQUARE_SIZE / 4);
                    circle.setFillColor(sf::Color::Red);
                    window.draw(circle);
                }
            }

        }

        window.display();
        window.clear();
    }

    return 0;
}
