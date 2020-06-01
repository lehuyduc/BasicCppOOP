#pragma once
#include <iostream>
#include "Point.hpp"
#include "Robot.hpp"
#include <queue>
using std::cout;

class SuperSmartRobot : public Robot {
    bool hasFoundExit;
    std::vector<Point> wayHome; // this vector stores the path to the exit of the maze

public:
    SuperSmartRobot(Point startPos);
    ~SuperSmartRobot();

    void findExit(const Maze& maze);

    virtual void go(const Maze& maze) override;

    void print() const override;
};


