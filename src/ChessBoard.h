//
// Created by auden on 2025-03-31.
//
#pragma once
#include "ChessPiece.cpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

constexpr int ROW_NUM = 8;
constexpr int COL_NUM = 8;


class ChessBoard {
private:
    int idArray[ROW_NUM][COL_NUM] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {17, 18, 19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32}
    };
public:


    sf::RectangleShape board[ROW_NUM][COL_NUM];

    ChessBoard();

    void createBoard();

    void displayBoard(sf::RenderWindow &window);

    int isSquareOccupied(int posX, int posY) const;
};
