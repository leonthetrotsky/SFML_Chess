//
// Created by auden on 2025-04-02.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Tile {
public:
    sf::RectangleShape tile;
    Tile(float posX, float posY, const sf::Color& color);

};

class ChessBoard {
public:
    ChessBoard();
    std::vector<std::vector<Tile>> board;

    void populateBoard();
    void display(sf::RenderWindow &window);
};
