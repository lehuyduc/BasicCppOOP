#include <iostream>
#include "UpRobot.hpp"
using std::cout;

UpRobot::UpRobot(Point startPos) : Robot(startPos) {}

UpRobot::~UpRobot() {}

void UpRobot::go(const Maze& maze) {
    int x = position.getX() - 1, y = position.getY();
    if (maze.valid(x,y) && !isCovered(x,y)) {moveTo(Point(x,y)); return;}
    goRandom(maze);
}

void UpRobot::print() const {
    cout << console::fg_yellow << "U";
}

