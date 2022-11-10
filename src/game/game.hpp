#include "board.hpp"
#include "game_kit.hpp"
#include "game_objects.hpp"
#include "snake.hpp"

#include <vector>

enum Direction {
    // TODO: create 4 directions
};

using GameObjects = std::vector<GameObject>;

class Game {
public:
    Game(Size boardSize);

public:
    bool isOver() const;
    void move(Direction dir); 

private:
    void setupBoard(); 
    // TODO: setup a scorebar underneath the gameboard in setupBoard()
    void displayBoard();
    void setupBoardBoundaries();
    void setupFood();
    void setupPlayer();
    void drawOnBoard(const GameObjects&);
    void drawOnBoard(const GameObject&);

private:
    GameKit gameKit_; // Object creation mechanism
    Board board_;
    GameObject player_; // Player is extended Snake?
    Food food_; // vector of 3 fruits
    Boundaries boundaries_; //  vector of top, bottom, left and right boundaries
    bool gameOver;
    // TODO: GameMode mode_;
    
};