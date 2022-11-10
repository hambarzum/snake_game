#include "board.hpp"
#include "game_objects.hpp"

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