#include "board.hpp"
#include "game_kit.hpp"
#include "game_objects.hpp"
#include "snake.hpp"

#include <vector>


enum Direction {
    // TODO: create 4 directions
};


class Game {
public:
    Game(Size boardSize);

public:
    bool gameStatus() const;
    void move(Direction dir); 

private:
    void setupBoard(); 
    // TODO: setup a scorebar underneath the gameboard in setupBoard()
    void displayBoard();
    void setupBoardBoundaries();
    void setupTopBoundary(Size boardSize);
    void setupBottomBoundary(Size boardSize);
    void setupLeftBoundary(Size boardSize);
    void setupRightBoundary(Size boardSize);
    void setupBoardObjects();
    void setupPlayer();
    void setupFruit();
    void drawBoundaries();
    void drawGameObjects();
    void drawPlayer();

private:
    //GameKit kit_;
    Board board_;
    Snake player_; // Player is extended Snake?
    GameObjects fruit_;
    GameObjects boundaries_; // top, bottom, left and right boundaries' vector // not obstacles if game mode is non-limit
    bool isOver;
    // TODO: GameMode mode_;
    
};