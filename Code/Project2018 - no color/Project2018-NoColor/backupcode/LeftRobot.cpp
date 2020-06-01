#include <iostream>
#include "LeftRobot.hpp"
using std::cout;

LeftRobot::LeftRobot(Point startPos) : Robot(startPos) {}

LeftRobot::~LeftRobot() {}

void LeftRobot::go(const Maze& maze) {
    int x = position.getX(), y = position.getY() - 1;
    if (maze.valid(x,y) && !isCovered(x,y)) moveTo(Point(x,y));
}

void LeftRobot::print() const {
    cout << "L";
}
