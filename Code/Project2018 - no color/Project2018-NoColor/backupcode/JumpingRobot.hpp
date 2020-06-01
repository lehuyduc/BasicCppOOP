#pragma once
#include <iostream>
#include "Robot.hpp"
using std::cout;

class JumpingRobot : public Robot{
    int maxJump;

public:
    JumpingRobot(Point startPos, int maxj);
    ~JumpingRobot();

    void go(const Maze& maze) override;

    void print() const override;
};

