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
    Size getSize();  
    // REDO
    void addTopBoundary(Size);
    void addBottomBoundary(Size);
    void addLeftBoundary(Size);
    void addRightBoundary(Size);

private: 
    Size boardSize_;
    Boundaries bounds_;
};