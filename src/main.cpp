#include <iostream>
#include <SFML/Graphics.hpp>
#include "ChessBoard.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({520u, 520u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    ChessBoard chessBoard;
    chessBoard.createBoard();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        chessBoard.displayBoard(window);
        window.display();
    }
}
