#include "events.hpp"

void Events::process(sf::RenderWindow& window, ChessBoard &chessboard) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
            window.close();

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
}