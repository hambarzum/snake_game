#include "snake.hpp"

Snake::Snake() 
    : head_{std::make_unique<Cell>(1,1)} // {0,0} {1,0} are boundary cells
{

}

Position Snake::getHeadPosition() const {
    return head_->getPosition();
}

int Snake::getTailLength () const {
    return tail_.size();
}