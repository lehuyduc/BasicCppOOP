#include <iostream>
#include "VerySmartRobot.hpp"
#include <random>
#include <queue>
using std::cout;

VerySmartRobot::VerySmartRobot(Point startPos,int depth,int rows, int cols) : Robot(startPos) {
    maxDepth = depth;
    nrow = rows;
    ncol = cols;
    arrived = new bool*[nrow];
    dist = new int*[nrow];
    tracer = new int*[nrow];
    for (int i=0;i<nrow;i++) {
        arrived[i] = new bool[ncol];
        dist[i] = new int[ncol];
        tracer[i] = new int[ncol];
    }
}

VerySmartRobot::~VerySmartRobot() {
    for (int i=0;i<nrow;i++) {
        delete[] arrived[i];
        delete[] dist[i];
        delete[] tracer[i];
    }
    delete arrived;
    delete dist;
    delete tracer;
    while (!qu.empty()) qu.pop();
}

// the same as in the smart robot
int VerySmartRobot::scoreFunction(const Maze& maze, Point location) const {
    if (!maze.valid(location.getX(), location.getY())) return 0;

    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    int score = 0;
    for (int k=0;k<4;k++) {
        int x = location.getX() + dx[k], y = location.getY() + dy[k];
        if (maze.valid(x,y) && Point(x,y)!=position) score++;
    }

    return score;
}

// this function returns a int from 0 to 3: the best direction to go
int VerySmartRobot::findBestDirection(const Maze& maze, const Point startPosition) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};

    // initialize Breadth First Search. This is very slow.
    // There are much faster way to initialize this,
    // but I will not add them here to keep things simple
    for (int i=0;i<maze.getNrow();i++)
    for (int j=0;j<maze.getNcol();j++) {
        arrived[i][j] = 0;
        tracer[i][j] = 0;
        dist[i][j] = 100000000; // initialize the distance array with very big numbers.
                                 // When we find the best cell to go, we choose the cell with lowest value.
    }

    // initialize the starting point

    arrived[startPosition.getX()][startPosition.getY()] = 1;
    dist[startPosition.getX()][startPosition.getY()] = 0;
    while (!qu.empty()) qu.pop();
    qu.push(startPosition);


    int highScore = 0;
    Point highScorePos = startPosition;
    while (!qu.empty()) {
        Point p = qu.front();
        qu.pop();
        int u = p.getX(), v = p.getY();

        for (int k=0;k<4;k++) {
            int x = u + dx[k], y = v + dy[k];
            if (maze.valid(x,y) && !arrived[x][y] && !isCovered(x,y)) {
                arrived[x][y] = true;
                dist[x][y] = dist[u][v] + 1;
                if (dist[x][y] < maxDepth) qu.push(Point(x,y)); // only push into queue if we haven't reached max searching depth
                tracer[x][y] = 3-k; // if k = 0 = down, 3-k = up, if k = 1 = right, 3-k = left.
                                    // We can use this to go back to the starting position from the cell with highest score

                int scoreHere = scoreFunction(maze, Point(x,y));
                if (scoreHere > highScore) {
                    highScore = scoreHere;
                    highScorePos = Point(x,y);
                }
            }
        }
    }


    Point cur = highScorePos; // trace back to the starting position from the cell with highest score
    while (cur!=startPosition) { // if we couldn't go anywhere, then this loop ends immediately, and we will return -1 below
        int x = cur.getX(), y = cur.getY();
        Point before = Point(x + dx[tracer[x][y]], y + dy[tracer[x][y]]);
        if (before==startPosition) // we have reached the starting position. So we return the direction to go from the starting position
            return 3 - tracer[x][y]; // we go from (x,y) -> before using tracer[x][y], so we go from Point before -> (x,y) using 3 - tracer[x][y]
        cur = before; // if not the starting point, then keep going back
    }

    return -1; // cannot go anywhere
}

void VerySmartRobot::go(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};
    int bestDirection = findBestDirection(maze,position);
    if (bestDirection==-1) { // cannot go anywhere
        goRandom(maze);
        return;
    }

    int x = position.getX() + dx[bestDirection], y = position.getY() + dy[bestDirection];
    if (maze.valid(x,y)) {moveTo(Point(x,y)); return;}
    goRandom(maze);
}

void VerySmartRobot::print() const {
    cout << console::fg_blue << "V";
}


