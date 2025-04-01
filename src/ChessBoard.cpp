//
// Created by auden on 2025-03-31.
//

#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {createBoard();}

void ChessBoard::createBoard() {
    constexpr sf::Color brownColor(120, 60, 0, 255);
    float xCount = 0;
    float yCount = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++ ) {
            sf::RectangleShape square({75.f, 75.f});
            square.setPosition({xCount, yCount});
            if (fmod(xCount + yCount, 2) != 0) {
                square.setFillColor(brownColor);
            }
            else {
                square.setFillColor(sf::Color::White);
            }
            xCount+=75;
            board[i][j] = square;
        }
        xCount = 0;
        yCount+=75;
    }
}

void ChessBoard::displayBoard(sf::RenderWindow &window) {
    for (auto &row : board) {
        for (auto &col : row) {
            window.draw(col);
        }
    }
}

int ChessBoard::isSquareOccupied(int posX, int posY) const {
    return idArray[posX][posY];
}