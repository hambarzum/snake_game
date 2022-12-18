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
    void run();
    void proccessInput(); // maybe private??  
    void updateState(); // maybe private??  
    void redraw(); // maybe private??  
    bool isOver();
    int getScore() const;

private:
    void constructScoreBoard();
    void setupInitSnake();
    void addFoodOnBoard();
    void eatFood();
    void removeFood();
    void increaseScore();
    bool foodExists() const;
    bool isOnFood(SnakePiece) const;
    bool isOnCollision(SnakePiece) const;
    bool isOnEmptyPosition(SnakePiece) const;
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