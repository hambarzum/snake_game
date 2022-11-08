#include "board.hpp"

Board::Board(Size boardSize)
    : boardSize_{boardSize}
{}

void Board::setSize(Size boardSize) {
    boardSize_ = boardSize;
}

Size Board::getSize() const {
    return boardSize_;
}

void Board::addTopBoundary(Size boardSize) {
    boundaries_.push_back(createTopBoundary(boardSize));
}

void Board::addBottomBoundary(Size boardSize) {
    boundaries_.push_back(createBottomBoundary(boardSize));
}

void Board::addLeftBoundary(Size boardSize) {
    boundaries_.push_back(createLeftBoundary(boardSize));
}

void Board::addRightBoundary(Size boardSize) {
    boundaries_.push_back(createRightBoundary(boardSize));
}

Boundary Board::createTopBoundary(Size boardSize) {
    Boundary topBound{boardSize.width};

    for(auto j = 0; j < boardSize.width; ++j) {
        topBound.push_back(Cell{0,j});
    }

    return topBound;
} // creates the boundary as a vector of cells

Boundary Board::createBottomBoundary(Size boardSize) {
    Boundary bottomBound{boardSize.width};

    for(auto j = 0; j < boardSize.width; ++j) {
        bottomBound.push_back(Cell{boardSize.height-1,j});
    }

    return bottomBound;
}

Boundary Board::createLeftBoundary(Size boardSize) {
    Boundary leftBound{boardSize.height};

    for(auto i = 0; i < boardSize.height; ++i) {
        leftBound.push_back(Cell{i,0});
    }

    return leftBound;
}

Boundary Board::createRightBoundary(Size boardSize) {
    Boundary rightBound{boardSize.height};

    for(auto i = 0; i < boardSize.height; ++i) {
        rightBound.push_back(Cell{i,boardSize.width-1});
    }

    return rightBound;
}
