#pragma once
#include <iostream>
#include "Robot.hpp"
using std::cout;

class DownRobot : public Robot{

public:
    DownRobot(Point startPos);
    ~DownRobot();

    void go(const Maze& maze) override;

    void print() const override;
};


