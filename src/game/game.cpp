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

void Game::setupTopBoundary() {
    
} 

void Game::setupBottomBoundary() {

}

void Game::setupLeftBoundary() {

}

void Game::setupRightBoundary() {

}

/// Setting up game objects

void Game::setupFruit() {
    fruit_.add();
}