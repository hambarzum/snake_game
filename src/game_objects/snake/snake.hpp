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
    SnakePiece(const Position&);

};

using SnakePieces = std::queue<SnakePiece>;

class Snake {
public:
    Snake();

public:
    void addPiece(const SnakePiece&);
    void removePiece();
    SnakePiece head() const;
    SnakePiece tail() const;
    Direction getDirection() const;
    void setDirection(const Direction&);
    SnakePiece createNewPiece() const;

private:
    Position locateNewPiecePosition() const;
    bool legalDirection(const Direction&) const;

private:
    SnakePieces snake_;
    Direction dir_;
};

#endif // SNAKE_HPP