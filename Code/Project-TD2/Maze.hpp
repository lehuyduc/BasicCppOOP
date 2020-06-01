#pragma once
#include <iostream>
#include "GenericCell.hpp"
using std::cout;

template<class T>
class Maze {
    int nrow, ncol;
    GenericPoint2D<T> exit;
    GenericCell<T> **cells;

protected:
    // we don't want people to access constructor of virtual class
    Maze() {}

public:

    bool inside(GenericPoint2D<T> pos) const {
        return pos.getX()>=0 && pos.getX()<nrow && pos.getY()>=0 && pos.getY()<ncol;
    }

    bool isWalled(GenericPoint2D<T> pos) const {
        if (!inside(pos)) return 1;
        int x = (int)pos.x, y = (int)pos.y;
        return cells[x][y].getFlag();
    }

    bool valid(GenericPoint2D<T> pos) {
        return inside(pos) && !isWalled(pos);
    }


    virtual void robotGo() = 0;
};
