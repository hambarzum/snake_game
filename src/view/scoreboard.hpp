#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "../game_objects/cell.hpp"
#include "board.hpp"

using Score = long long unsigned int;

class ScoreBoard {
public:
    ScoreBoard();
    ScoreBoard(Size, Position);

public:
    void clear();
    void refresh();
    void initialize(Score initScore);
    void displayUpdatedScore(Score score);

private:
    void printScoreBoard();

private:
    WINDOW* scoreboardWindow_;
    Size size_;
    Position pos_;
};

#endif // SCOREBOARD_HPP