#pragma once
#include <iostream>
#include <vector>
#include "Random.hpp"
#include "Maze.hpp"
using std::cout;

class RandomMaze : public Maze {
    int nwall, maxLength;

public:
    RandomMaze(int rows, int cols, int walls, int maxLen);

    ~RandomMaze();

    void generateWalls() override;
};
