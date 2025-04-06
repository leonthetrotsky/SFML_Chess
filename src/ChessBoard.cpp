//
// Created by auden on 2025-04-02.
//

#include "ChessBoard.h"
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

Tile::Tile(float posX, float posY, const sf::Color& color) {

    this->tile = sf::RectangleShape({100.f, 100.f});
    this->tile.setPosition({posX, posY});
    this->tile.setFillColor(color);
    std::cout << "new object made";
}

ChessBoard::ChessBoard() {
    board = std::vector<std::vector<Tile>>(8);
}

void ChessBoard::populateBoard() {
    float xPos = 0;
    float yPos = 0;
    sf::Color dark = sf::Color(112,102,119);
    sf::Color light = sf::Color(204,183,174);

    board[0].emplace_back(1, 1, dark);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((j+i) % 2 == 0) {
                board[i].push_back(Tile(xPos, yPos, light));
            }
            else {
                board[i].push_back(Tile(xPos, yPos, dark));
            }
            xPos += 100;
        }
        xPos = 0;
        yPos += 100;
    }
}

void ChessBoard::display(sf::RenderWindow &window) {
    for (const auto& row : board) {
        for (const auto& col : row) {
            window.draw(col.tile);
        }
    }
}
