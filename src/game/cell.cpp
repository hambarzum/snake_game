#include "cell.hpp"

Cell::Cell()
    : pos_{0,0}
{}

Cell::Cell(Coord x, Coord y) {
        pos_.x = x;
        pos_.y = y;
}

void Cell::setX(Coord x) {
        pos_.x = x;
}

Coord Cell::getX() const {
        return pos_.x;
} 

void Cell::setY(Coord y) {
        pos_.y = y;
}

Coord Cell::getY() const {
    return pos_.y;
}
