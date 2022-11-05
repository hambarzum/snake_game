#include "board.hpp"
#include "game_object.hpp"
#include "snake.hpp"

#include <vector>

using GameObjects = std::vector<GameObject>;

struct Size {
    int height;
    int width;

};

enum Direction {
    // TODO: create 4 directions
};

class Game {
public:
    Game(Size boardSize);

public:
    bool gameStatus();
    void move(Direction dir); 

private:
    void setupBoard();
    void displayBoard();
    void setupBoardBoundaries();
    void setupBoardObjects();
    void setupPlayer();
    void setupTopBoundary();
    void setupBottomBoundary();
    void setupLeftBoundary();
    void setupRightBoundary();
    void setupFruit();
private:
    Board board_;
    Snake player_;
    GameObjects fruit_;
    // TODO: GameMode mode_;
    bool isOver = false;
};