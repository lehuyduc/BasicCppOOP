#include <iostream>
#include "Maze.hpp"

Maze::Maze(int rows, int cols) : nrow(rows), ncol(cols) {
    walled = new bool*[nrow];
    for (int i=0;i<nrow;i++) {
        walled[i] = new bool[ncol];
        for (int j=0;j<ncol;j++) walled[i][j] = 0;
    }
}

Maze::~Maze() {
    for (int i=0;i<nrow;i++) delete[] walled[i];
    delete walled;
}

int Maze::getNrow() const {return nrow;}
int Maze::getNcol() const {return ncol;}
Point Maze::getExit() const {return exit;}

void Maze::setExit(const Point& p) {exit = p;}

bool Maze::inside(int x,int y) const { // return true if the cell is inside the maze
    return (x>=0 && x<nrow && y>=0 && y<ncol);
}

bool Maze::isWalled(int x,int y) const { // return true if the cell is outside the maze, or is a wall
    if (!inside(x,y)) return true;
    return walled[x][y];
}

bool Maze::valid(int x,int y) const { // return true if that cell is inside the maze and is not a wall
    return inside(x,y) && !isWalled(x,y);
}

void Maze::updatePrint() {
    std::vector<int> escapedRobots;
    escapedRobots.clear();

    for (int i=0;i<nrow;i++) {
        for (int j=0;j<ncol;j++ ) {
            if (Point(i,j)==exit) {
                cout << "X";

                // if a robot has same position as exit
                for (int k=0;k<robots.size();k++)
                    if (robots[k]->getPosition()==exit)
                        escapedRobots.push_back(k);

                continue;
            }


            bool printed = 0;
            for (int k=0;k<robots.size();k++) {
                Robot *r = robots[k];

                if (r->getPosition()==Point(i,j)) {
                    r->print();
                    printed = 1;
                    break;
                }
            }

            if (!printed) {
                if (walled[i][j]) cout << "1";
                else cout << "0";
            }
        }
        cout << "\n";
    }

    for (int k=int(escapedRobots.size())-1;k>=0;k--) {
        cout << "A robot has escaped!!!\n";
        robots.erase(robots.begin() + escapedRobots[k]); // delete the robot from the matrix
    }
    escapedRobots.clear();
}


void Maze::addRobot(Robot* r) {
    robots.push_back(r);
}

void Maze::robotGo() {
    for (int i=0;i<robots.size();i++) robots[i]->go(*this);
}
