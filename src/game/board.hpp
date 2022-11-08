// #define boundaries_[0] bouddaries_.top
// #define boundaries_[1] bouddaries_.bottom
// #define boundaries_[2] bouddaries_.left
// #define boundaries_[3] bouddaries_.right

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
    Size getSize() const; 
    void setSize(Size);
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