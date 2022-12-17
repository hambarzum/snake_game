#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <queue>

#include "../drawable.hpp"

enum Direction {
    up = -1,
    down = 1,
    left = -2,
    right = 2
}; // values assigned for legal direction movement check (i.e. can't move left when current direction is right)

class SnakePiece : public Drawable {
public:
    SnakePiece(Position);
    
private:

};

using SnakeBody = std::queue<SnakePiece>;

class Snake {
public:
    Snake();

public: // maybe private??
    void addPiece(SnakePiece);
    void removePiece();
    SnakePiece head();
    SnakePiece tail();
    Direction getDirection() const;
    void setDirection(Direction);
    SnakePiece createNewPiece();

private:
    bool legalDirection(Direction);

private:
    SnakeBody snake_;
    Direction dir_;
};

#endif // SNAKE_HPP