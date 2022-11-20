#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "../board/cell.hpp"

#include <memory> // std::unique_ptr
#include <vector>

using Head = std::unique_ptr<Cell>;

class Snake {
public:
    Snake();

public:
    Position getHeadPosition() const;
    int getTailLength() const;

private:
    Head head_;
    Tail tail_;
};

#endif // SNAKE_HPP