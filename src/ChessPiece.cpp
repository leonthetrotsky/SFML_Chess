//
// Created by auden on 2025-03-31.
//

#include "ChessPiece.h"


class ChessPiece {
private:
    int positionX;
    int positionY;
    int pieceNumber{};
    static int pieceCounter;

public:
    virtual ~ChessPiece() = default;

    int pieceId;
    ChessPiece(int xPos_, int yPos_) : positionX(xPos_), positionY(yPos_) {pieceCounter++; pieceId = ChessPiece::pieceCounter;};

    static bool checkOffMap(int xPos, int yPos) {
        return (xPos > 7 || xPos < 0 || yPos > 7 || yPos < 0);
    }

    virtual void moveChoice();
    constexpr bool isWhitePiece() const {
        return pieceId <= 16;
    }
};

class Pawn : public ChessPiece {
private:
public:
    Pawn(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};

class Rook : public ChessPiece {
private:
public:
    Rook(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};

class Bishop : public ChessPiece {
private:
public:
    Bishop(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};

class Knight : public ChessPiece {
private:
public:
    Knight(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};

class Queen : public ChessPiece {
private:
public:
    Queen(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};

class King : public ChessPiece {
private:
public:
    King(int xPos_, int yPos_) : ChessPiece(xPos_, yPos_) {};
};