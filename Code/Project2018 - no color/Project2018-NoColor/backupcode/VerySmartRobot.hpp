#pragma once
#include <iostream>
#include "Point.hpp"
#include "Robot.hpp"
#include <queue>
using std::cout;

// We can create SuperSmartRobot and UltimateSmartRobot with better AI later
class VerySmartRobot : public Robot {
    int maxDepth;
    int nrow, ncol; // the VerySmartRobot requires to know the dimension of the matrix.
    bool **arrived; // we maintain a matrix of whether we have arrived this point
    std::queue<Point> qu; // we need a queue for breadth first search
    int **dist; // distance from a point. this 2d array will be used for breadth first search to find the cell with highest score
    int **tracer; // we use this array to go back from the cell with the highest score to the original position to find the best direction

public:
    VerySmartRobot(Point, int, int, int);
    ~VerySmartRobot();

    int scoreFunction(const Maze& maze, Point location) const;

    int findBestDirection(const Maze&, const Point);  // we use breadth first search to evaluate score function of each tile

    void go(const Maze& maze) override;

    void print() const override;
};




