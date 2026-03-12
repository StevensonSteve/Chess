#include "constants.hpp"
#include "board.hpp"
#include "figures.hpp"
#include "renderer.hpp"
#include "events.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");
    ChessBoard chessboard;
    FiguresShapes figuresShapes;
    FigurePosition figurePosition;

    Board::init(chessboard);
    figuresShapes = Figures::init();
    
    while (window.isOpen()) {
        
        Events::process(window, chessboard, figurePosition);
        
        window.clear();
        
        Renderer::drawBoard(window);
        Renderer::highlightActiveCell(window, figurePosition.x, figurePosition.y);
        Renderer::drawFigures(window, chessboard, figuresShapes);

        window.display();
    }

    return 0;
}
