#ifndef GAME_HPP
#define GAME_HPP

#include "../board/board.hpp"
#include "../players/player.hpp"
#include "../snake/snake.hpp"
#include "game_objects/food.hpp"
#include "game_objects/game_object.hpp"
#include "game_kit.hpp"


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
    void setupGame(); 
    // TODO: setup a scorebar underneath the gameboard in setupBoard()
    void displayGame();
    void setupBoardBoundaries();
    void setupFood();
    void setupPlayer();
    void drawOnBoard(const GameObject&);

private:
    Board board_;
    Player player_;
    Food food_;
    Boundaries boundaries_; //  vector of top, bottom, left and right boundaries
    bool gameOver;
//  GameMode mode_; TODO
    
};

#endif // GAME_HPP