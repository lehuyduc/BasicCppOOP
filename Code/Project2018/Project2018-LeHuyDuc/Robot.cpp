#include <iostream>
#include <vector>
#include "Robot.hpp"
using std::cout;

void Robot::moveTo(const Point& newPosition) {
    position = newPosition;
    covered.push_back(position);
}

void Robot::cleanup() {
    covered.clear();
}

void Robot::copy(const Robot& r) {
    if (this==&r) return;
    cleanup();
    position = r.position;
    covered = r.covered; // std::vector has defined operator=
}

Robot::Robot(const Robot& r) {
    copy(r);
}

Robot::Robot(Point startPos) {position = startPos; covered.clear(); covered.push_back(startPos);}

Robot::~Robot() {cleanup();}

Robot& Robot::operator=(const Robot& r) { // teacher Aveneau code like this
    if (this!=&r) {
        cleanup();
        copy(r);
    }
    return *this;
}

Point Robot::getPosition() const {return position;}

bool Robot::isCovered(Point p) const {
    for (int i=0;i<covered.size();i++) if (covered[i]==p) return true;
    return false;
}

bool Robot::isCovered(int x,int y) const {
    for (int i=0;i<covered.size();i++) if (covered[i]==Point(x,y)) return true;
    return false;
}

// use this when the robot hsa nowhere to go
void Robot::goRandom(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    int from = rand()%4;                // if we don't do this, the robots will always try down, right, left, up (D R L U)
    for (int t=from;t<from+4;t++) {     // by doing this, the robots can try the directions in any order: R L U D, L U D R, U D R L, ...
        int k = rand()%4;
        int x = position.getX() + dx[k], y = position.getY() + dy[k];
        if (maze.valid(x,y)) {
            moveTo(Point(x,y));
            return;
        }
    }
}
