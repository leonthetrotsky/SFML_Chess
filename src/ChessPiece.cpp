//
// Created by auden on 2025-03-31.
//

#include "ChessPiece.h"

class ChessPiece {
private:
    int positionX{};
    int positionY{};
    int pieceId{};
    static int pieceCounter;

public:
    ChessPiece(int xPos_, int yPos_) : positionX(xPos_), positionY(yPos_) {pieceCounter++; this->pieceId = pieceCounter;};

    bool checkOffMap() const {
        return (this->positionX > 7 || this->positionX < 0 || this->positionY > 7 || this->positionY < 0);
    }

    bool isWhitePiece() const {
        return this->pieceId <= 16;
    }
};

class Pawn;

class Rook;

class Bishop;

class Knight;

class Queen;

class King;