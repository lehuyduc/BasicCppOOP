#pragma once
#include <iostream>
#include "GenericPoint2D.hpp"
#include "GenericMaze.hpp"
#include <vector>
using std::cout;

template <class T>
class GenericRobot {

protected:
    GenericPoint2D<T> position;
    std::vector<GenericPoint2D<T> > covered;

public:
    GenericRobot<T>(GenericPoint2D<T> startPosition) {
        position = startPosition;
        covered.clear();
        covered.push_back(position);
    }

    GenericPoint2D<T> getPosition() const {return position;}


    void moveTo(GenericPoint2D<T> newpos) {
        position = newpos;
        covered.push_back(position);
    }

    bool isCovered(GenericPoint2D<T> p) {
        for (int i=0;i<covered.size();i++) if (covered[i]==p) return true;
        return false;
    }

    // use this when the robot has nowhere to go
    void goRandom(const GenericMaze<T> &maze) {
        const int dx[4] = {1,0,0,-1};
        const int dy[4] = {0,1,-1,0};

        int from = rand()%4;                // if we don't do this, the robots will always try down, right, left, up (D R L U)
        for (int t=from; t<from+4; t++) {   // by doing this, the robots can try the directions in any order: R L U D, L U D R, U D R L, ...
            int k = rand()%4;

            int x = position.getX() + dx[k], y = position.getY() + dy[k];
            if (maze.valid(GenericPoint2D<T>(x,y))) {
                moveTo(GenericPoint2D<T>(x,y));
                return;
            }
        }
    }


    virtual void go(const GenericMaze<T> &maze) = 0;

    virtual void print() const = 0;
};
