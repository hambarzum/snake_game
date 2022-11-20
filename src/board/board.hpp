#ifndef BOARD_HPP
#define BOARD_HPP

#include "game/game_objects/boundary.hpp"
#include "cell.hpp"

#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <vector>

struct Size {
    int height;
    int width;
};

using Boundaries = std::vector<Boundary>;
using Matrix = std::vector<std::vector<Cell>>;

class Board {
public:
    Board(Size boardSize);
    ~Board();
public:
    void setSize(Size);
    Size getSize() const;
    void display();
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
    void init();
    void print();

private: 
    WINDOW* window_;
    Size boardSize_;
    Matrix boardMatrix;
    Boundaries boundaries_; // vector of top, bottom, left and right boundaries
};

#endif // BOARD_HPP