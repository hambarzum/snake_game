#pragma once

#include <vector>

#include "board.hpp"
#include "game_object.hpp"
#include "menu.hpp"
#include "snake.hpp"


using GameObjects = std::vector<GameObject>;

class Game {
public:
    Game(Menu mainMenu, Board& board, Snake& snake);

public:
    bool isOver();
    void 

private:
    Menu mainMenu_;
    Board board_;
    Snake player_;
    GameObject fruit_;
};