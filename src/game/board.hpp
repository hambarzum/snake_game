#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <vector>

using Size = int;


class Board {
public:
    Board(Size boardSize);

private:
    void setupBoard();
    
private: 
    Size boardSize_;

};