#ifndef BOARD_HPP
#define BOARD_HPP

#include <stdlib.h>
#include <time.h>

#include "../game_objects/cell.hpp"

struct Size {
    int height;
    int width;
};

using CellPtr = Cell*;

class Board {
public:
    Board();
    Board(Size boardSize);
    ~Board();
    
public:
    Size getSize() const;
    Character getInput() const;
    void refresh();
    void drawOnBoard(Cell);
    Position getEmptyPosition();
    bool isEmpty(Position);
    Position getBoardPosition() const;

private:
    void createBoardWindow(Size);
    void setupWindow();
    Size calculateMaxSize();
    Position getCenterPosition(Size maxSize, Size boardSize);
    void initializeBoard();
    void clear();
    void drawBorders();
    Position generateRandomPosition();
    Character getCharacterAt(Position) const;

private:
    WINDOW* boardWindow_; // abstarct away??
    Size boardSize_;
    Position boardPos_;
};

#endif // BOARD_HPP
