#include "cell.hpp"

#include <memory> // std::unique_ptr
#include <vector>

using Head = std::unique_ptr<Cell>;
using Body = std::vector<std::unique_ptr<Cell>>; 
using Length = int;

class Snake {
public:
    Snake();

public:
    Position getHeadPosition() const;
    Length getBodyLength() const;

private:
    Head head_;
    Body body_;
};