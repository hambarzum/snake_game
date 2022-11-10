#include "game.hpp"

Game::Game(Size boardSize) 
    : board_{boardSize}, gameOver{false}
{
    setupBoard();
    displayBoard();
    // TODO: Setup scorebar
}

/// Setting up the board

void Game::setupBoard() {
    setupBoardBoundaries();
    setupFood();
    setupPlayer();
}

void Game::setupBoardBoundaries() {
    const Size boardSize = board_.getSize();

    boundaries_.push_back(gameKit_.createTopBoundary(boardSize));
    boundaries_.push_back(gameKit_.createBottomBoundary(boardSize));
    boundaries_.push_back(gameKit_.createLeftBoundary(boardSize));
    boundaries_.push_back(gameKit_.createRightBoundary(boardSize)); 
 
}

/// Setting up game objects

void Game::setupPlayer() {
    // player_ = gameKit_.createPlayer();
}

void Game::setupFood() {
    // TODO
}

void Game::displayBoard() {
    drawOnBoard(boundaries_);
    drawOnBoard(food_);
    drawOnBoard(player_);
}

bool Game::isOver() const {
    return gameOver;
}