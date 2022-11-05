#include "game.hpp"

Game::Game(Size boardSize) 
    : board_(boardSize)
{
    setupBoard();
    displayBoard();
}

/// Setting up the board

void Game::setupBoard() {
    setupBoardBoundaries();
    setupBoardObjects();
    setupPlayer();
}

void Game::setupBoardBoundaries() {
    setupTopBoundary();
    setupBottomBoundary();
    setupLeftBoundary();
    setupRightBoundary();
}

void Game::setupBoardObjects() {
    setupFruit();
}

void Game::setupPlayer() {

}

/// Setting up board boundaries

void Game::setupTopBoundary(Size boardSize) {
    board_.addTopBoundary(boardSize); 
} 

void Game::setupBottomBoundary(Size boardSize) {

}

void Game::setupLeftBoundary(Size boardSize) {

}

void Game::setupRightBoundary(Size boardSize) {

}

/// Setting up game objects

void Game::setupFruit() {
    fruit_.add();
}