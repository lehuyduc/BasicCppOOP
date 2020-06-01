#include <iostream>
#include "DownRobot.hpp"
using std::cout;

DownRobot::DownRobot(Point startPos) : Robot(startPos) {}

DownRobot::~DownRobot() {}

void DownRobot::go(const Maze& maze) {
    int x = position.getX() + 1, y = position.getY();
    if (maze.valid(x,y) && !isCovered(x,y)) {moveTo(Point(x,y)); return;}
    goRandom(maze);
}

void DownRobot::print() const {
    cout << console::fg_yellow << "D";
}
