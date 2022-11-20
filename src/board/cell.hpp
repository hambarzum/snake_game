#ifndef CELL_HPP
#define CELL_HPP

using Coord = int;

struct Position {
    Coord x;
    Coord y;
};

class Cell {
public:
    Cell();
    Cell(Coord x, Coord y);

public:
    void setX(Coord x);
    Coord getX() const;
    void setY(Coord y);
    Coord getY() const;
    Position getPosition() const;
private:
    Position pos_;
};

#endif // CELL_HPP