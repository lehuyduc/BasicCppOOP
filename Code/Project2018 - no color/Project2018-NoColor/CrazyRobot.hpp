#pragma once
#include <iostream>
#include "Point.hpp"
#include "Robot.hpp"
using std::cout;

class CrazyRobot : public Robot {
public:
    CrazyRobot(Point startPos);
    ~CrazyRobot();

    void go(const Maze& maze) override;

    void print() const override;
};

