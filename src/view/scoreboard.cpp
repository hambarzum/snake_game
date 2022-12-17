#include "scoreboard.hpp"

ScoreBoard::ScoreBoard() {

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
    displayScoreBoard();
    displayUpdatedScore(initScore);
    refresh();
}

void ScoreBoard::displayUpdatedScore(Score score) {
    mvwprintw(scoreboardWindow_, 0, scoreboardWindow_->_maxx - 10, "%11llu", score);
}

void ScoreBoard::displayScoreBoard() {
    mvwprintw(scoreboardWindow_, 0, 0, "Score:");
}