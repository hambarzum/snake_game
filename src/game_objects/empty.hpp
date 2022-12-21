#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "cell.hpp"

class Empty : public Cell{
public:
    Empty(const Position& pos);
    
};

#endif // EMPTY_HPP