/// IF ANY ADDITIONS, MOVE IMPLEMENTATION TO SEPERATE .cpp FILE

using Coord = int;

class Cell {
public:
    Cell() 
        : x_{0}, y_{0}
    {}
 
    Cell(Coord x, Coord y) {
        x_ = x;
        y_ = y;
    }

public:
    void setX(Coord x) {
        x_ = x;
    }

    Coord getX() const {
        return x_;
    } 

    void setY(Coord y) {
        y_ = y;
    }

    Coord getY() const {
        return y_;
    }

private:
    Coord x_;
    Coord y_;
};