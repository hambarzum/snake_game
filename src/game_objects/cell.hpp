#ifndef CELL_HPP
#define CELL_HPP

#include <ncurses.h>

struct Position {
    int row;
    int column;
};

using Character = chtype;

class Cell {
public:
    Cell();
    Cell(Position pos, Character character);

public:
    Position getPosition() const;
    Character getIcon() const;

protected:
    Position pos_;
    Character icon_;
};

#endif // CELL_HPP