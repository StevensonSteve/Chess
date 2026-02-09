#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

const int BOARD_SIZE = 16;
const float SQUARE_SIZE = 50.f;

char getSquareColor(int x, int y) {
    if ((x + y) % 2 == 0) {
        return 'W';
    } else {
        return 'B';
    }    
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    float size = SQUARE_SIZE;
    char highlighted[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
                highlighted[i][j] = getSquareColor(i, j);
        }
    }

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
                cout << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y << "\n";
                highlighted[y][x] = 'R';
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                int x = event.mouseButton.x / (int)size;
                int y = event.mouseButton.y / (int)size;
                cout << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y << "\n";
                highlighted[y][x] = getSquareColor(x, y);
            }
        }        

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                sf::RectangleShape rect(sf::Vector2f(size, size));
                rect.setPosition(j * size, i * size);

                // if (highlighted[i][j] == 'W') {
                //     rect.setFillColor(sf::Color::White);
                // } else if (highlighted[i][j] == 'B') {
                //     rect.setFillColor(sf::Color(100, 100, 100));
                // } else if (highlighted[i][j] == 'R') {
                //     rect.setFillColor(sf::Color::Red);
                // }
                
                
                switch (highlighted[i][j]) {
                    case 'W':
                        rect.setFillColor(sf::Color::White);
                        break;
                    case 'B':
                    rect.setFillColor(sf::Color(100, 100, 100));
                        break;
                    case 'R':
                        rect.setFillColor(sf::Color::Red);
                        break;
                    // default:
                    //     std::cout << "This is a middle row (2-5)." << std::endl;
                    //     break;
                }

                window.draw(rect);
            }
        }
        
        window.display();
        window.clear();
    }
    return 0;
}
