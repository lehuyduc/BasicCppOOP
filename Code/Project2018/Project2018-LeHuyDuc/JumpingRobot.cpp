#include <iostream>
#include "JumpingRobot.hpp"
using std::cout;

JumpingRobot::JumpingRobot(Point startPos,int maxj) : Robot(startPos), maxJump(maxj) {}

JumpingRobot::~JumpingRobot() {}

void JumpingRobot::go(const Maze& maze) { // we do not need to add the word override here. We can but not needed
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    int from = rand()%4; // pick one random direction to start from
    for (int t=from; t<from+4; t++) { // try all 4 directions to make sure that the robot can go somewhere
        int k = t%4;
        int range = rand()%maxJump + 1; // pick a random jump range

        int x = position.getX() + range*dx[k], y = position.getY() + range*dy[k];
        if (maze.inside(x,y) && !isCovered(x,y)) {moveTo(Point(x,y)); return;} // we allow this robot to jump ON TOP OF walls ?
    }
    goRandom(maze);
}

void JumpingRobot::print() const{
    cout << console::fg_magenta << "J";
}

