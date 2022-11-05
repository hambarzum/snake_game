#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <vector>

struct Size {
    int height;
    int width;
};


class Board {
public:
    Board(Size boardSize);

public:
    Size getSize();
    // REDO
    void addTopBoundary(Size);
    void addBottomBoundary(Size);
    void addLeftBoundary(Size);
    void addRightBoundary(Size);

private: 
    Size boardSize_;

};