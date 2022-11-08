#include "snake.hpp"

Snake::Snake() 
    : head_{1,1} // {0,0} {1,0} are boundary cells
{

}

Head Snake::getHeadPosition() const {
    return head_;
}

Length Snake::getBodyLength () const {
    return body_.size();
}