#include "game_kit.hpp"
#include "snake.hpp"
Snake GameKit::createTopBoundary(Size boardSize) {
    Boundary topBound{boardSize.width};

    for(auto j = 0; j < boardSize.width; ++j) {
        topBound.push_back(Cell{0,j});
    }

    return Snake{};
} // creates the boundary as a vector of cells

GameObject GameKit::createBottomBoundary(Size boardSize) {
    Boundary bottomBound{boardSize.width};

    for(auto j = 0; j < boardSize.width; ++j) {
        bottomBound.push_back(Cell{boardSize.height-1,j});
    }

    return bottomBound;
}

GameObject GameKit::createLeftBoundary(Size boardSize) {
    Boundary leftBound{boardSize.height};

    for(auto i = 0; i < boardSize.height; ++i) {
        leftBound.push_back(Cell{i,0});
    }

    return leftBound;
}

GameObject GameKit::createRightBoundary(Size boardSize) {
    Boundary rightBound{boardSize.height};

    for(auto i = 0; i < boardSize.height; ++i) {
        rightBound.push_back(Cell{i,boardSize.width-1});
    }

    return rightBound;
}