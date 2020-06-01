#pragma once
#include <iostream>
#include "GenericRobot.hpp"
#include "random"
using std::cout;

template<class T>
class GenericCrazyRobot : public GenericRobot<T> {

public:
    GenericCrazyRobot(GenericPoint2D<T> startPosition) : GenericRobot<T>(startPosition) {}

    void go(const GenericMaze<T> &maze) override {
        const int dx[4] = {1,0,0,-1};
        const int dy[4] = {0,1,-1,0};

        // if we only try one direction, then the robot might not move at all this turn. So we try all 4 directions in 1 go()
        //
        int from = rand()%4;                 // if we don't do this, the robots will always try down, right, left, up (D R L U)
        for (int t=from; t<from+4; t++) {    // by doing this, the robots can try the directions in any order: R L U D, L U D R, U D R L, ...
            int k = t%4;
            GenericPoint2D<T> newPos = GenericPoint2D<T>(this->position.getX() + dx[k], this->position.getY() + dy[k]);
            if (this->position.getX()==0 && this->position.getY()==10) cout << newPos << " AA\n";
            if (maze.valid(newPos) && !GenericRobot<T>::isCovered(newPos)) {GenericRobot<T>::moveTo(newPos); return;}
        }

        GenericRobot<T>::goRandom(maze);
    }

    void print() const override {
        cout << console::fg_red << "C";
    }
};
