#include <time.h>
#include <stdlib.h>

#include "../game_objects/empty.hpp"
#include "play.hpp"

Game::Game(const WindowPtr win) 
    : window_(win),
    food_(nullptr),
    score_(0),
    gameOver_(false) 
{
    srand(time(NULL)); // randomizer
    setupInitSnake(); // initializes snake of 1 piece
    addFoodOnBoard();
}

Game::~Game() {
    gameOver_ = true; // in case exits without game ending (i.e. Esc)
    removeFood();
}

void Game::setupInitSnake() {  
    const SnakePiece initPiece(Position{2,2});
    addPieceToHead(initPiece); // initializes snake of 1 piece in {2, 2} position
}

void Game::addPieceToHead(const SnakePiece& newHead) {
    if(!isOver()) {
        snake_.addPiece(newHead);
        window_->drawCell(newHead);
    }
}

void Game::addFoodOnBoard() {
    food_ = new Food(findEmptyPosition());
    window_->drawCell(*food_);
}

Position Game::findEmptyPosition() const {
    Position pos = generateRandomPosition();

    while(!isEmpty(pos)) {
        pos = generateRandomPosition();
    }

    return pos;
}

Position Game::generateRandomPosition() const {
    return Position{rand() % (window_->getSize().width - 1), rand() % (window_->getSize().height - 2)}; // assures position is inside board
}

bool Game::isEmpty(const Position& pos) const {
    return window_->getCharacterAt(pos) == ' ';
}

void Game::run() {
    while(!isOver()){
        proccessInput();
        updateState();
        redraw();
    }
}

bool Game::isOver() const {
    return gameOver_;
}

void Game::proccessInput() {
    const char input = window_->getInput();

    switch(input) {
        case 'w':
            snake_.setDirection(up);
            break;
        case 's':
            snake_.setDirection(down);
            break;
        case 'a':
            snake_.setDirection(left);
            break;
        case 'd':
            snake_.setDirection(right);
            break;
        case 27: // Esc ASCII code
            gameOver_ = true;
            break;
        default:
            break;
        // TODO: 'p' or 'space' for pause
    }
}

void Game::updateState() {
    handleSnakeMovement();
}

void Game::handleSnakeMovement() {
    const SnakePiece newHead = snake_.createNewPiece();

    handlePossibleOutcomes(newHead);

    addPieceToHead(newHead);

    if(!foodExists()) {
        addFoodOnBoard(); 
    }
}

void Game::handlePossibleOutcomes(const SnakePiece& newHead) {
    if(isOnEmptyPosition(newHead)) {
        removeTail();
    }

    else if(isOnFood(newHead)) {
        eatFood();
    }

    else if(isOnCollision(newHead)) {
        gameOver_ = true;
    }
}

bool Game::isOnEmptyPosition(const SnakePiece& newHead) const {
    return isEmpty(newHead.getPosition());
}

bool Game::isOnFood(const SnakePiece& head) const {
    return head.getPosition().column == food_->getPosition().column && head.getPosition().row == food_->getPosition().row; // checks if both are same Position
}

bool Game::isOnCollision(const SnakePiece& newHead) const {
    return (!isOnEmptyPosition(newHead) && !isOnFood(newHead));
}

void Game::eatFood() {
    removeFood();
    increaseScore();
}

void Game::removeFood() {
    window_->drawCell(Empty(food_->getPosition()));
    delete food_;
    food_ = nullptr;
}

void Game::increaseScore() {
    score_ += 100;
    window_->drawScoreBoard(score_);
}

void Game::removeTail() {
    window_->drawCell(Empty(snake_.tail().getPosition()));
    snake_.removePiece();
}

bool Game::foodExists() const {
    return food_ != nullptr;
}

void Game::redraw() const{
    window_->refresh();
}

int Game::getScore() const {
    return score_;
}