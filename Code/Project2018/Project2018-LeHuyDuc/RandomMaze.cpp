#include <iostream>
#include "RandomMaze.hpp"
using std::cout;

RandomMaze::RandomMaze(int rows, int cols, int walls, int maxLen) : Maze(rows,cols), nwall(walls), maxLength(maxLen) {}

RandomMaze::~RandomMaze() {}

void RandomMaze::generateWalls() {
    static const int dx[4] = {1,0,0,-1}; // 4 directions
    static const int dy[4] = {0,1,-1,0};

    int dem = 0;
    while (dem < nwall) {
        int i = Random::rand()%nrow, j = Random::rand()%ncol;
        if (walled[i][j]) continue; // if there's already a wall here

        int from = Random::rand()%4;
        int wallLength = Random::rand()%maxLength + 1; // pick a random wall length
        for (int it=from; it<from+4; it++) { // pick a random wall direction
            int k = it%4;
            int x = i + (wallLength-1)*dx[k], y = j + (wallLength-1)*dy[k];
            if (!inside(x,y)) continue;

            for (int t=0;t<wallLength;t++)
                walled[i + t*dx[k]][j + t*dy[k]] = 1; // assign the values
            dem += 1;
            break;
        }
    }
}


