#include "board.hpp"

Board::Board(Size boardSize)
    : boardSize_{boardSize}
{
    

}

Size Board::getSize() {
    return boardSize_;
}

void Board::setSize(Size boardSize) {
    boardSize_ = boardSize;
}