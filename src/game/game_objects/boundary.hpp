#include "game_object.hpp"

using CellVector = std::vector<Cell>;

class Boundary : public GameObject{
public:
    Boundary();

public:
    

private:
    CellVector boundary_;
};