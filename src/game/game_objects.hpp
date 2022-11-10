#include "cell.hpp"

class GameObject {
public:
    GameObject();
    
public:
    Position getPosition() const; // returns the cell position of the object, the top left cell position if object is bigger than 1 cell

private:
    Position pos_;
};

/// GameObject: Boundary

using CellVector = std::vector<Cell>;

class Boundary : public GameObject{
public:
    Boundary();

public:

private:
    CellVector boundary_;
};

/// GameObject: Food

class Food : public GameObject {
public:
    Food();

private:

};