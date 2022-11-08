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
    // void setupBoardBoundaries();
    void setupBoardObjects(GameObjects);
    void setupBoardObject(GameObject);
    void setupPlayer();
    void setupFruit();
    void drawOnBoard();

private:
    GameKit gameKit_;
    Board board_;
    GameObject player_; // Player is extended Snake?
    GameObjects fruits_; // vector of 3 fruits
    GameObjects boundaries_; // top, bottom, left and right boundaries' vector // not obstacles if game mode is non-limit
    bool isOver;
    // TODO: GameMode mode_;
    
};