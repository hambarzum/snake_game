#ifndef GAME_HPP
#define GAME_HPP

#include "../game_objects/food.hpp"
#include "../game_objects/snake/snake.hpp"
#include "../window/ncurses_window.hpp"

using FoodPtr = Food*;

class Game {
public:
    Game(const WindowPtr);
    ~Game();

public:
    void run();
    bool isOver();
    int getScore() const;

private:
    void proccessInput();
    void updateState();
    void redraw(); 

private:
    void setupInitSnake();
    void addPieceToHead(SnakePiece);
    void addFoodOnBoard();

private:
    Position findEmptyPosition();
    Position generateRandomPosition();
    bool isEmpty(Position) const;

private:
    void handleSnakeMovement();
    void handlePossibleOutcomes(SnakePiece newHead);
    
private:
    void eatFood();
    void removeFood();
    void increaseScore();
    bool foodExists() const;

private:
    bool isOnFood(SnakePiece) const;
    bool isOnCollision(SnakePiece) const;
    bool isOnEmptyPosition(SnakePiece) const;
    void removeTail();

private:
    const WindowPtr window_;
    bool gameOver_;
    Snake snake_;
    FoodPtr food_;
    int score_;
    // int speed_;
};

#endif // GAME_HPP