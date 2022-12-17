#include "snake.hpp"

SnakePiece::SnakePiece(Position pos) {
    pos_ = pos;
    icon_ = '*';
} // give the SnakePiece a nice icon if possible

Snake::Snake() {
    dir_ = down;
}

void Snake::addPiece(SnakePiece piece) {
    snake_.push(piece);
}

void Snake::removePiece() {
    snake_.pop();
}

SnakePiece Snake::head() {
    return snake_.back();
}

SnakePiece Snake::tail() {
    return snake_.front(); 
}

Direction Snake::getDirection() const {
    return dir_;
}

void Snake::setDirection(Direction dir) {
    if(legalDirection(dir)){
        dir_ = dir;
    }
}

SnakePiece Snake::createNewPiece() {
    SnakePiece newPiece(locateNewPiecePosition());

    return newPiece;
}

Position Snake::locateNewPiecePosition() {
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

bool Snake::legalDirection(Direction dir) {
    return (dir_ + dir);
}