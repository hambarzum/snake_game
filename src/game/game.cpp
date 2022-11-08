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
    setupBoardObjects(boundaries_);
    setupBoardObjects(fruits_);
    setupPlayer();
}

void Game::setupBoardObjects(GameObjects objects) {
    const Size boardSize = board_.getSize();

    boundaries_.push_back(board_.addTopBoundary(boardSize));
    boundaries_.push_back(board_.addBottomBoundary(boardSize));
    boundaries_.push_back(board_.addLeftBoundary(boardSize));
    boundaries_.push_back(board_.addRightBoundary(boardSize));

    for(auto obj : objects) {
        setupBoardObject(obj);
    }
}

void Game::setupBoardObject(GameObject obj) {
    obj = gameKit_.addObject();
}

/// Setting up game objects

void Game::setupBoardObjects(GameObjects objects) {
    // TODO
}

void Game::setupPlayer() {
    player_;
}

void Game::setupFruits() {
    // TODO
}

void Game::displayBoard() {
    drawOnBoard(boundaries_);
    drawOnBoard(fruits_);
    drawOnBoard();
}

bool Game::gameStatus() const {
    return isOver;
}