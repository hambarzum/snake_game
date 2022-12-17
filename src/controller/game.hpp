#ifndef GAME_HPP
#define GAME_HPP

#include "../game_objects/food.hpp"
#include "../game_objects/snake/snake.hpp"
#include "../view/board.hpp"
#include "../view/scoreboard.hpp"


using FoodPtr = Food*;

class Game {
public:
    Game(Size boardSize);
    ~Game();

public:
    bool isOver();

public: // private later??
    void run();
    void proccessInput();
    void updateState();
    void redraw();
    int getScore() const;

private:
    void constructScoreBoard();
    void setupInitSnake();
    void addFoodOnBoard();
    void eatFood();
    void removeFood();
    void increaseScore();
    bool foodExists();
    bool isOnFood(SnakePiece);
    bool isOnCollision(SnakePiece);
    bool isOnEmptyPosition(SnakePiece);
    void removeTail();
    void addPieceToHead(SnakePiece);
    void handleSnakeMovement();
    void handlePossibleOutcomes(SnakePiece newHead); // Game and SnakePiece strongly coupled??

private:
    Board board_;
    bool gameOver_;
    Snake snake_;
    FoodPtr food_;
    ScoreBoard scoreBoard_;
    Score score_;
};

#endif // GAME_HPP