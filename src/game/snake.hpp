#include "cell.hpp"

#include <vector>

using Head = Cell;
using Body = std::vector<Cell>; 
using Length = int;

class Snake {
public:
    Snake();

public:
    Head getHeadPosition() const;
    Length getBodyLength() const;

private:
    Head head_;
    Body body_;
};