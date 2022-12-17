#include <iostream>
#include <ncurses.h>

#include "src/controller/game.hpp"
#include "src/game_objects/drawable.hpp"

constexpr int BOARD_HEIGHT = 20;
constexpr int BOARD_WIDTH = 30;

int main() {

    initscr();
    refresh();
    noecho();
    curs_set(0);

    Size boardSize = {BOARD_HEIGHT, BOARD_WIDTH};
    Game game(boardSize);
    game.run();

    endwin();

    std::cout << '\a';
    return 0;
}