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

