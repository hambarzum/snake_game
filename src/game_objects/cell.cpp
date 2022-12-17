#include "cell.hpp"

Cell::Cell() {
    pos_.row = 0;
    pos_.column = 0;
    icon_ = ' ';
}

Cell::Cell(Position pos, Character character) {
    pos_ = pos;
    icon_ = character;
}

Position Cell::getPosition() const {
    return pos_;
}

Character Cell::getIcon() const {
    return icon_;
}