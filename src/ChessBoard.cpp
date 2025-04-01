//
// Created by auden on 2025-03-31.
//

#include "ChessBoard.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class ChessBoard {
private:
    //This displays the "real" positions of all pieces
    int idArray[8][8] = {
        {2, 3, 4, 5, 6, 4, 3, 2},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 4, 5, 6, 4, 3, 2}};

    sf::RectangleShape board[8][8];
public:

    ChessBoard() {createBoard();}

    void createBoard() {
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

    void displayBoard(sf::RenderWindow &window) {
        for (auto &row : board) {
            for (auto &col : row) {
                window.draw(col);
            }
        }
    }

};
