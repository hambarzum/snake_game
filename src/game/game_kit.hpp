#ifndef GAME_KIT_HPP
#define GAME_KIT_HPP

#include "../board/board.hpp"
#include "game_objects/game_object.hpp"

class GameKit {
public:
    GameKit();

public:
    Snake createTopBoundary(Size boardSize);
    GameObject createBottomBoundary(Size boardSize);
    GameObject createLeftBoundary(Size boardSize);
    GameObject createRightBoundary(Size boardSize);
    void createPlayer(); // TODO

private:
    // GameObjects objects;
};

#endif // GAME_KIT_HPP