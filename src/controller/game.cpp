#include "../game_objects/empty.hpp"
#include "game.hpp"


Game::Game(Size boardSize) 
    : board_(boardSize), 
    food_(nullptr),
    score_(0),
    gameOver_(false) 
{
    srand(time(NULL)); // randomizer
    
    constructScoreBoard();
    setupInitSnake(); // initializes snake of 1 piece
    addFoodOnBoard(); 
}

Game::~Game() {
    gameOver_ = true; // in case exits without game ending (i.e. ctrl+c)
    removeFood();
}

void Game::constructScoreBoard() {
    Size sbSize = Size{1, board_.getSize().width};
    Position sbPos = Position{board_.getBoardPosition().row + board_.getSize().height, board_.getBoardPosition().column}; // places scoreboard underneath the board
    scoreBoard_ = ScoreBoard(sbSize, sbPos);

    scoreBoard_.initialize(score_);
}

void Game::setupInitSnake() {  
    SnakePiece initPiece(Position{2,2});
    addPieceToHead(initPiece); // initializes snake of 1 piece in {2, 2} position
}

void Game::addPieceToHead(SnakePiece newHead) {
    if(!isOver()) {
        snake_.addPiece(newHead);
        board_.drawOnBoard(newHead); // maybe draw whole snake on board seperately?? window/draw abstraction
    }
}

void Game::addFoodOnBoard() {
    food_ = new Food(board_.findEmptyPosition());
    board_.drawOnBoard(*food_); // maybe draw on board seperately?? window/draw abstraction
}

void Game::run() {
    while(!isOver()){
        proccessInput();
        updateState();
        redraw();
    }
}

bool Game::isOver() {
    return gameOver_;
}

void Game::proccessInput() {
    Character input = board_.getInput();

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
        default:
            break;
        // TODO: 'p' for pause??
    } // TODO: handle as events seperately
} // ! BUG: any keypress fastens the movement

void Game::updateState() {
    handleSnakeMovement();
} // check if reached winning score, end win window

void Game::handleSnakeMovement() {
    SnakePiece newHead = snake_.createNewPiece();

    handlePossibleOutcomes(newHead);

    addPieceToHead(newHead);

    if(!foodExists()) {
        addFoodOnBoard(); 
    }
}

void Game::handlePossibleOutcomes(SnakePiece newHead) {
    if(isOnEmptyPosition(newHead)) {
        removeTail();
    }

    else if(isOnFood(newHead)) {
        eatFood();
    }

    else if(isOnCollision(newHead)) {
        gameOver_ = true;
    }
} // lift if possible??


bool Game::isOnEmptyPosition(SnakePiece newHead) const {
    return board_.isEmpty(newHead.getPosition());
}

bool Game::isOnFood(SnakePiece head) const {
    return head.getPosition().column == food_->getPosition().column && head.getPosition().row == food_->getPosition().row; // checks if both are same Position
}

bool Game::isOnCollision(SnakePiece newHead) const {
    return (!isOnEmptyPosition(newHead) && !isOnFood(newHead));
}

void Game::eatFood() {
    removeFood();
    increaseScore();
}

void Game::removeFood() {
    board_.drawOnBoard(Empty(food_->getPosition()));
    delete food_;
    food_ = nullptr;
}

void Game::increaseScore() {
    score_ += 100;
    scoreBoard_.displayUpdatedScore(score_);
}

void Game::removeTail() {
    board_.drawOnBoard(Empty(snake_.tail().getPosition()));
    snake_.removePiece();
}

bool Game::foodExists() const {
    return food_ != nullptr;
}

void Game::redraw() {
    board_.refresh();
    scoreBoard_.refresh();
}

int Game::getScore() const {
    return score_;
}