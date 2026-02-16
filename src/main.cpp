#include "constants.hpp"
#include "board.hpp"
#include "figures.hpp"
#include "renderer.hpp"
#include "events.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    ChessBoard chessboard;
    FiguresShapes figuresShapes;

    Board::init(chessboard);
    figuresShapes = Figures::init();
    
    while (window.isOpen()) {
        
        Events::process(window, chessboard);
        
        window.clear();
        
        Renderer::drawBoard(window);
        Renderer::drawFigures(window, chessboard, figuresShapes);

        window.display();

    }

    return 0;
}
