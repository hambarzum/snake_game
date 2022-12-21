#ifndef FOOD_HPP
#define FOOD_HPP

#include "cell.hpp"

class Food : public Cell {
public:
    Food(const Position& pos);
    
};

#endif // FOOD_HPP