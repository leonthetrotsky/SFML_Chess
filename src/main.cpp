#include <iostream>
#include <SFML/Graphics.hpp>
#include "ChessBoard.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "Chess Game");
    window.setFramerateLimit(144);


    ChessBoard chessBoard;
    chessBoard.populateBoard();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        chessBoard.display(window);

        window.display();
    }
}
