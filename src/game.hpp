#pragma once

#include <vector>

#include "board.hpp"
#include "menu.hpp"

using GameObjects = std::vector<GameObject>;

class Game {
public:
    Game(Menu mainMenu, Board board, Snake snake);

private:
    Menu mainMenu_;
    Board board_;
    Snake snake_;
    GameObject fruit_;
};