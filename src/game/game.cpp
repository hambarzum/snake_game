#include "game.hpp"

Game::Game(Size boardSize) 
    : board_{boardSize}, isOver{false}
{
    setupBoard();
    displayBoard();
    // TODO: Setup scorebar
}

/// Setting up the board

void Game::setupBoard() {
    setupBoardBoundaries();
    setupBoardObjects();
    setupPlayer();
}

void Game::setupBoardBoundaries() {
    const Size boardSize = board_.getSize();

    boundaries_.push_back(board_.addTopBoundary(boardSize));
    boundaries_.push_back(board_.addBottomBoundary(boardSize));
    boundaries_.push_back(board_.addLeftBoundary(boardSize));
    boundaries_.push_back(board_.addRightBoundary(boardSize));
}


/// Setting up game objects

void Game::setupBoardObjects() {
    setupFruit();
}

void Game::setupPlayer() {
    player_;
}

void Game::setupFruit() {
    // TODO
}

void Game::displayBoard() {
    drawBoundaries();
    drawGameObjects();
    drawPlayer();
}

bool Game::gameStatus() const {
    return isOver;
}