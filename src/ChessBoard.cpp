//
// Created by auden on 2025-04-02.
//

#include "ChessBoard.h"
#include <cmath>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

Tile::Tile(float posX, float posY, const sf::Color& color) {

    this->tile = sf::RectangleShape({100.f, 100.f});
    this->tile.setPosition({posX, posY});
    this->tile.setFillColor(color);
}

ChessBoard::ChessBoard() {
    board = std::vector<std::vector<Tile>>(8);
}

void ChessBoard::populateBoardWithTiles() {
    float xPos = 0;
    float yPos = 0;
    sf::Color dark = sf::Color(112,102,119);
    sf::Color light = sf::Color(204,183,174);



    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((j+i) % 2 == 0) {
                board[i].emplace_back(xPos, yPos, light);
            }
            else {
                board[i].emplace_back(xPos, yPos, dark);
            }
            xPos += 100;
        }
        xPos = 0;
        yPos += 100;
    }
}

void ChessBoard::populateBoardWithPieces() {
    int id = 0; // Unique ID for each piece

    // Black back rank (row 0)
    std::vector<sf::Texture*> blackBackRank = {
        &blackRook, &blackHorse, &blackBishop, &blackQueen,
        &blackKing, &blackBishop, &blackHorse, &blackRook
    };
    for (int col = 0; col < 8; ++col) {
        float x = board[0][col].tile.getPosition().x;
        float y = board[0][col].tile.getPosition().y;

        chessPieces.insert(std::pair<int, ChessPiece*>(id++, new ChessPiece(x, y, *blackBackRank[col])));
    }

    // Black pawns (row 1)
    for (int col = 0; col < 8; ++col) {
        float x = board[1][col].tile.getPosition().x;
        float y = board[1][col].tile.getPosition().y;

        chessPieces.insert(std::pair<int, ChessPiece*>(id++, new ChessPiece(x, y, blackPawn)));
    }

    // White pawns (row 6)
    for (int col = 0; col < 8; ++col) {
        float x = board[6][col].tile.getPosition().x;
        float y = board[6][col].tile.getPosition().y;
        chessPieces.insert(std::pair<int, ChessPiece*>(id++, new ChessPiece(x, y, whitePawn)));
    }

    // White back rank (row 7)
    std::vector<sf::Texture*> whiteBackRank = {
        &whiteRook, &whiteHorse, &whiteBishop, &whiteQueen,
        &whiteKing, &whiteBishop, &whiteHorse, &whiteRook
    };
    for (int col = 0; col < 8; ++col) {
        float x = board[7][col].tile.getPosition().x;
        float y = board[7][col].tile.getPosition().y;
        chessPieces.insert(std::pair<int, ChessPiece*>(id++, new ChessPiece(x, y, *whiteBackRank[col])));
    }
}

void ChessBoard::display(sf::RenderWindow &window) {
    for (const auto& row : board) {
        for (const auto& col : row) {
            window.draw(col.tile);
        }
    }

    for (const auto&[fst, snd] : chessPieces) {
        window.draw(snd->getSprite());
    }
}
