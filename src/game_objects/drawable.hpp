#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ncurses.h>

struct Position {
    int row;
    int column;
};

using Character = chtype;

class Drawable {
public:
    Drawable();
    Drawable(Position pos, Character character);

public:
    Position getPosition() const;
    Character getIcon() const;

protected:
    Position pos_;
    Character icon_;
};

#endif // DRAWABLE_HPP