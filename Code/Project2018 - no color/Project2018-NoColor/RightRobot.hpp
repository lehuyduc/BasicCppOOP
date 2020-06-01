#pragma once
#include <iostream>
#include "Robot.hpp"
using std::cout;

class RightRobot : public Robot{

public:
    RightRobot(Point startPos);
    ~RightRobot();

    void go(const Maze& maze) override;

    void print() const override;
};


