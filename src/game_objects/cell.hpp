#ifndef CELL_HPP
#define CELL_HPP

struct Position {
    int row;
    int column;
};

class Cell {
public:
    Cell();
    Cell(Position pos, char character);

public:
    Position getPosition() const;
    char getIcon() const;

protected:
    Position pos_;
    char icon_; // alias??
};

#endif // CELL_HPP