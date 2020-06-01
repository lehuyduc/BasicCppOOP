#pragma once
#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Maze.hpp"
using std::cout;

class Maze;

class Robot {
private:
    // We do not want anyone to call Robot()
    Robot() {};

protected:
    Point position;
    std::vector<Point> covered;

    void moveTo(const Point& newPosition);

    void cleanup();

    void copy(const Robot&);

public:
    Robot(const Robot&);
    Robot(Point startPos);
    virtual ~Robot();

    Robot& operator=(const Robot& r);

    Point getPosition() const;

    bool isCovered(Point) const;

    bool isCovered(int,int) const;

    void goRandom(const Maze&);

    //--------
    virtual void go(const Maze& maze) = 0 ;

    virtual void print() const = 0;
};
