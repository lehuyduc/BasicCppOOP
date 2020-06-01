#pragma once
#include <iostream>
#include "Point.hpp"
#include "Robot.hpp"
using std::cout;

class SmartRobot : public Robot {
public:
    SmartRobot(Point startPos);
    ~SmartRobot();

    int scoreFunction(const Maze& maze, Point location) const;

    virtual void go(const Maze& maze) override;

    void print() const override;
};


