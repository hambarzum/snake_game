#include "board.hpp"

Board::Board() {
    // TODO: implement if necessary
}

Board::Board(Size boardSize) {
    boardSize_ = boardSize;

    createBoardWindow(boardSize);
    initializeBoard();
    refresh();
}

Board::~Board() {
    // getch(); 
    // endwin();
} // add an endscreen saying "game over, press key to restart" if possible

void Board::createBoardWindow(Size boardSize) {
    setupWindow();
    boardPos_ = getCenterPosition(calculateMaxSize(), boardSize); // BUG: doesn't work if moved to Board ctor
    boardWindow_ = newwin(boardSize.height, boardSize.width, boardPos_.row, boardPos_.column); 
    refresh();
    
    wtimeout(boardWindow_, 175); // abstract away? maybe add difficulty levels??
}

Size Board::calculateMaxSize() {
    int maxHeight, maxWidth;
    getmaxyx(stdscr, maxHeight, maxWidth); // assigns max values of the screen to parameters maxHeight and maxWidth

    Size maxSize{maxHeight, maxWidth};
    return maxSize;
}

Position Board::getCenterPosition(Size maxSize, Size boardSize) {
    Position centerPos = {(maxSize.height/2) - (boardSize.height/2), (maxSize.width/2) - (boardSize.width/2)};
    return centerPos;
}

void Board::setupWindow() {
    /* initscr();
    refresh();
    noecho();
    curs_set(0); */
}

void Board::initializeBoard() {
    clear();
    drawBorders(); 
    refresh();
}

void Board::clear() {
    wclear(boardWindow_);
}

void Board::refresh() {
    wrefresh(boardWindow_);
}

void Board::drawBorders() {
    box(boardWindow_, 0, 0);
}

Size Board::getSize() const {
    return boardSize_;
}

Character Board::getInput() const {
    return wgetch(boardWindow_);
}

void Board::drawOnBoard(Drawable object) {
    mvwaddch(boardWindow_, object.getPosition().column, object.getPosition().row, object.getIcon());
}

Position Board::getEmptyPosition() {
    Position pos = generateRandomPosition();

    while(!isEmpty(pos)) {
        pos = generateRandomPosition();
    }

    return pos;
}

Position Board::generateRandomPosition() {
    return Position{rand() % (getSize().width - 1), rand() % (getSize().height - 1)}; // assures position is inside board
}

bool Board::isEmpty(Position pos) {
    return getCharacterAt(pos) == ' ';
}

Character Board::getCharacterAt(Position pos) const {
    return mvwinch(boardWindow_, pos.column, pos.row);
}

Position Board::getPosition() const {
    return boardPos_;
}