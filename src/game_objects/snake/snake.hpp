#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <queue>

#include "../cell.hpp"

enum Direction {
    up = -1,
    down = 1,
    left = -2,
    right = 2
}; // values assigned for legal direction movement checks (i.e. can't move left when current direction is right)

class SnakePiece : public Cell {
public:
    SnakePiece(Position);

};

using SnakePieces = std::queue<SnakePiece>;

class Snake {
public:
    Snake();

public:
    void addPiece(SnakePiece);
    void removePiece();
    SnakePiece head();
    SnakePiece tail();
    Direction getDirection() const;
    void setDirection(Direction);
    SnakePiece createNewPiece();

private:
    Position locateNewPiecePosition();
    bool legalDirection(Direction);

private:
    SnakePieces snake_;
    Direction dir_;
};

#endif // SNAKE_HPP