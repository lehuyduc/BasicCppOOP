#include <iostream>
#include "SmartRobot.hpp"
#include <random>
using std::cout;

SmartRobot::SmartRobot(Point startPos) : Robot(startPos) {}

SmartRobot::~SmartRobot() { }

int SmartRobot::scoreFunction(const Maze& maze, Point location) const {
    if (!maze.valid(location.getX(), location.getY())) return 0;

    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    int score = 0;
    for (int k=0;k<4;k++) {
        int x = location.getX() + dx[k], y = location.getY() + dy[k];
        if (maze.valid(x,y) && Point(x,y)!=position) score++;
    }

    return score;
}

void SmartRobot::go(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};
    int score[4] = {0,0,0,0};

    int highScore=0, pos=-1;
    for (int k=0;k<4;k++) {
        int i = position.getX() + dx[k], j = position.getY() + dy[k];
        if (!maze.valid(i,j) || isCovered(i,j)) continue;
        score[k] = scoreFunction(maze,Point(i,j));
        if (score[k] > highScore) {highScore = score[k]; pos = k;}
    }

    if (pos!=-1) {
        int x = position.getX() + dx[pos], y = position.getY() + dy[pos];
        if (maze.valid(x,y)) moveTo(Point(x,y));
    }

}

void SmartRobot::print() const {
    cout << "S";
}

