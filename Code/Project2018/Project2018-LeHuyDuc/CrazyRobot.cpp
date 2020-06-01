#include <iostream>
#include "CrazyRobot.hpp"
#include <random>
using std::cout;

CrazyRobot::CrazyRobot(Point startPos) : Robot(startPos) {}

CrazyRobot::~CrazyRobot() { }

void CrazyRobot::go(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    // if we only try one direction, then the robot might not move at all this turn. So we try all 4 directions in 1 go()
    //
    int from = rand()%4;                // if we don't do this, the robots will always try down, right, left, up (D R L U)
    for (int t=from;t<from+4;t++) {     // by doing this, the robots can try the directions in any order: R L U D, L U D R, U D R L, ...
        int k = t%4;
        int x = position.getX() + dx[k], y = position.getY() + dy[k];
        if (maze.valid(x,y) && !isCovered(x,y)) {
            moveTo(Point(x,y));
            return;
        }
    }
    goRandom(maze);
}

void CrazyRobot::print() const {
    cout << console::fg_red << "C";
}
