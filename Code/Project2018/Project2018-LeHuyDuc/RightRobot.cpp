#include <iostream>
#include "RightRobot.hpp"
using std::cout;

RightRobot::RightRobot(Point startPos) : Robot(startPos) {}

RightRobot::~RightRobot() {}

void RightRobot::go(const Maze& maze) {
    int x = position.getX(), y = position.getY() + 1;
    if (maze.valid(x,y) && !isCovered(x,y)) {moveTo(Point(x,y)); return;}
    goRandom(maze);
}

void RightRobot::print() const {
    cout << console::fg_yellow << "R";
}
