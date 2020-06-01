#include <iostream>
#include "SuperSmartRobot.hpp"
#include <random>
using std::cout;

SuperSmartRobot::SuperSmartRobot(Point startPos) : Robot(startPos) {
    wayHome.clear();
    hasFoundExit = false;
}

SuperSmartRobot::~SuperSmartRobot() {
    wayHome.clear();
}

void SuperSmartRobot::findExit(const Maze& maze) {
    const int dx[4] = {1,0,0,-1}; // down, right, left, up
    const int dy[4] = {0,1,-1,0};
    // this function use breadth first search to find the way to the exit
    std::queue<Point> qu;
    bool **arrived;
    Point **tracer;
    Point exit = maze.getExit();
    int nrow = maze.getNrow(), ncol = maze.getNcol();
    // this initialization method is NOT EFFICIENT.
    // But since this is a simple project, I will keep the implementation simple.

    arrived = new bool*[nrow];
    tracer = new Point*[nrow];
    for (int i=0;i<nrow;i++) {
        arrived[i] = new bool[ncol];
        tracer[i] = new Point[ncol];
        for (int j=0;j<nrow;j++) {
            arrived[i][j] = 0;
            tracer[i][j] = Point(-1,-1);
        }
    }

    // we start from Point position
    arrived[position.getX()][position.getY()] = 1;
    tracer[position.getX()][position.getY()] = Point(position.getX(), position.getY());
    while (!qu.empty()) qu.pop();
    qu.push(position);

    bool foundExit = false;
    while (!qu.empty()) {
        Point p = qu.front(); qu.pop();
        int u = p.getX(), v = p.getY();

        for (int k=0;k<4;k++) {
            int x = u+dx[k], y = v+dy[k];

            if (maze.valid(x,y) && !arrived[x][y]) {
                arrived[x][y] = true;
                tracer[x][y] = Point(u,v);
                if (Point(x,y)==exit) {foundExit = true; break;}
                qu.push(Point(x,y));
            }
        }

        if (foundExit) break;
    }

    cout << "found exit = " << foundExit << "\n";
    if (foundExit) {
        hasFoundExit = true;
        Point cur = exit;

        while (cur!=position) {
            wayHome.push_back(cur);
            cur = tracer[cur.getX()][cur.getY()];
        }
    }

    for (int i=0;i<nrow;i++) {
        delete[] arrived[i];
        delete[] tracer[i];
    }
    delete arrived;
    delete tracer;
}

void SuperSmartRobot::go(const Maze& maze) {
    if (!hasFoundExit) findExit(maze);
    if (hasFoundExit && wayHome.size()>0) {
        int l = wayHome.size() - 1;
        moveTo(wayHome[l]);
        wayHome.erase(wayHome.begin()+l);
    }
}

void SuperSmartRobot::print() const {
    cout << console::fg_blue << "E";
}

