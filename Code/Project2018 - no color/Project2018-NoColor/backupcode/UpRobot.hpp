#pragma once
#include <iostream>
#include "Robot.hpp"
using std::cout;

class UpRobot : public Robot{

public:
    UpRobot(Point startPos);
    ~UpRobot();

    void go(const Maze& maze) override;

    void print() const override;
};

