#include "cell.hpp"

#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <vector>

struct Size {
    int height;
    int width;
};

using Boundary = std::vector<Cell>;
using Boundaries = std::vector<Boundary>;

class Board {
public:
    Board(Size boardSize);

public:
    void setSize(Size);
    Size getSize() const;
    void addTopBoundary(Size);
    void addBottomBoundary(Size);
    void addLeftBoundary(Size);
    void addRightBoundary(Size);
    Boundary createTopBoundary(Size boardSize);
    Boundary createBottomBoundary(Size boardSize);
    Boundary createLeftBoundary(Size boardSize);
    Boundary createRightBoundary(Size boardSize);

private: 
    Size boardSize_;
    Boundaries boundaries_{4}; // top, bottom, left and right boundaries' vector
};