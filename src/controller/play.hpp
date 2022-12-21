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
    bool isOver() const;
    int getScore() const;

private:
    void proccessInput();
    void updateState();
    void redraw() const;

private:
    void setupInitSnake();
    void addPieceToHead(const SnakePiece&);
    void addFoodOnBoard();
    Position findEmptyPosition() const;
    Position generateRandomPosition() const;
    bool isEmpty(const Position&) const;

private:
    void handleSnakeMovement();
    void handlePossibleOutcomes(const SnakePiece& newHead);
    
private:
    bool isOnEmptyPosition(const SnakePiece&) const;
    bool isOnFood(const SnakePiece&) const;
    bool isOnCollision(const SnakePiece&) const;

private:
    void removeTail();
    void eatFood();
    void removeFood();
    void increaseScore();
    bool foodExists() const;

private:
    const WindowPtr window_;
    bool gameOver_;
    Snake snake_;
    FoodPtr food_;
    int score_;
};

#endif // GAME_HPP