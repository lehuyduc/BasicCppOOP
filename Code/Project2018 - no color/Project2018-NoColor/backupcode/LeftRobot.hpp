#pragma once
#include <iostream>
#include "Robot.hpp"
using std::cout;

class LeftRobot : public Robot{

public:
    LeftRobot(Point startPos);
    ~LeftRobot();

    void go(const Maze& maze) override;

    void print() const override;
};
