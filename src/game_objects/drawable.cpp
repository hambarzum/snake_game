#include "drawable.hpp"

Drawable::Drawable() {
    pos_.row = 0;
    pos_.column = 0;
    icon_ = ' ';
}

Drawable::Drawable(Position pos, Character character) {
    pos_ = pos;
    icon_ = character;
}

Position Drawable::getPosition() const {
    return pos_;
}

Character Drawable::getIcon() const {
    return icon_;
}