#include "game.hpp"

Game::Game(Size boardSize)
    : board_{boardSize}, gameOver{false}
{
    setupGame();
    displayGame();
    // TODO: Setup scorebar
}


void Game::setupGame()
{
    setupBoardBoundaries();
    setupFood();
    setupPlayer();
}

void Game::setupBoardBoundaries()
{
    const Size boardSize = board_.getSize();

}

void Game::setupPlayer()
{
    // player_ = gameKit_.createPlayer();
}

void Game::setupFood()
{
    // TODO
}

void Game::displayGame()
{
    board_.display();
    // drawOnBoard(food_);
    // drawOnBoard(snake_);
}

bool Game::isOver() const
{
    return gameOver;
}