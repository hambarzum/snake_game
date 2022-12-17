#include "scoreboard.hpp"

ScoreBoard::ScoreBoard() {
    // implement if necessary
}

ScoreBoard::ScoreBoard(Size size, Position pos) 
    : size_(size),
    pos_(pos)
{
    scoreboardWindow_ = newwin(size.height, size.width, pos.row, pos.column);
}

void ScoreBoard::clear() {
    wclear(scoreboardWindow_);
}

void ScoreBoard::refresh() {
    wrefresh(scoreboardWindow_);
}

void ScoreBoard::initialize(Score initScore) {
    clear();
    printScoreBoard();
    displayUpdatedScore(initScore);
    refresh();
}

void ScoreBoard::displayUpdatedScore(Score score) {
    mvwprintw(scoreboardWindow_, 0, scoreboardWindow_->_maxx - 10, "%11llu", score);
}

void ScoreBoard::printScoreBoard() {
    mvwprintw(scoreboardWindow_, 0, 0, "Score:");
}