#include <iostream>
#include "CrazyRobot.hpp"
#include <random>
using std::cout;

CrazyRobot::CrazyRobot(Point startPos) : Robot(startPos) {}

CrazyRobot::~CrazyRobot() { }

void CrazyRobot::go(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};
    int k = rand()%4; // pick one random direction
    int x = position.getX() + dx[k], y = position.getY() + dy[k];
    if (maze.valid(x,y) && !isCovered(x,y)) moveTo(Point(x,y));
}

void CrazyRobot::print() const {
    cout << "C";
}
