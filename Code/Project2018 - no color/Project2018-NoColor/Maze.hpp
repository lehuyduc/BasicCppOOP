#pragma once
#include <iostream>
#include <vector>
#include "Robot.hpp"
#include "Point.hpp"
using std::cout;

class Robot;

class Maze {

protected:
    const int nrow, ncol;
    Point exit;
    bool **walled; // walled[i][j] = true if there's a wall
    std::vector<Robot*> robots;

public:
    Maze(int rows, int cols);

    ~Maze();

    int getNrow() const;
    int getNcol() const;
    Point getExit() const;

    void setExit(const Point& p);

    bool inside(int x,int y) const;     // return true if the cell is inside the maze

    bool isWalled(int i,int j) const;   // return true if the cell is outside the maze, or is a wall

    bool valid(int i,int j) const;      // return true if that cell is inside the maze and is not a wall

    void updatePrint();

    void addRobot(Robot*);

    void robotGo();                     // tell all robots to go
    //---
    virtual void generateWalls() = 0;

};
