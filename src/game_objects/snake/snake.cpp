#include "snake.hpp"

SnakePiece::SnakePiece(const Position& pos) {
    pos_ = pos;
    icon_ = '*';
}

Snake::Snake() {
    dir_ = down;
}

void Snake::addPiece(const SnakePiece& piece) {
    snake_.push(piece);
}

void Snake::removePiece() {
    snake_.pop();
}

SnakePiece Snake::head() const {
    return snake_.back();
}

SnakePiece Snake::tail() const {
    return snake_.front(); 
}

Direction Snake::getDirection() const {
    return dir_;
}

void Snake::setDirection(const Direction& dir) {
    if(legalDirection(dir)){
        dir_ = dir;
    }
}

SnakePiece Snake::createNewPiece() const {
    const SnakePiece newPiece(locateNewPiecePosition());
    return newPiece;
}

Position Snake::locateNewPiecePosition() const {
    Position pos = head().getPosition();

    switch(dir_) {
        case down:
            pos.column++;
            break;
        case up:
            pos.column--;
            break;
        case left:
            pos.row--;
            break;
        case right:
            pos.row++;
            break;    
    }

    return pos;
}

bool Snake::legalDirection(const Direction& dir) const {
    return (dir_ + dir);
}