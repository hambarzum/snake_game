#include "cell.hpp"
#include "game_objects.hpp"

#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <vector>

struct Size {
    int height;
    int width;
};


using Boundaries = std::vector<Boundary>;

class Board {
public:
    Board(Size boardSize);

public:
    void setSize(Size);
    Size getSize() const;
/*
    void addTopBoundary(Size);
    void addBottomBoundary(Size);
    void addLeftBoundary(Size);
    void addRightBoundary(Size);
    Boundary createTopBoundary(Size boardSize);
    Boundary createBottomBoundary(Size boardSize);
    Boundary createLeftBoundary(Size boardSize);
    Boundary createRightBoundary(Size boardSize); 
*/

private: 
    Size boardSize_;
    Boundaries boundaries_{4}; // vector of top, bottom, left and right boundaries
};