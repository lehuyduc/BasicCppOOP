#pragma once
#include <iostream>
#include "GenericCell.hpp"
#include <vector>
using std::cout;

template <class T>
class GenericRobot;

template<class T>
class GenericMaze {

protected:
    int nrow, ncol;
    GenericPoint2D<T> exit;
    GenericCell<T> **cells;
    std::vector<GenericRobot<T>*> robots;
    // we don't want people to access constructor of virtual class
    Maze() {}

public:
    GenericMaze(int rows, int cols) : nrow(rows), ncol(cols){
        cells = new GenericCell<T>*[nrow];
        for (int i=0;i<nrow;i++) {
            cells[i] = new GenericCell<T>[ncol];
            for (int j=0;j<ncol;j++) {
                cells[i][j].setLoc(GenericPoint2D<T>(i,j));
                cells[i][j].setFlag(0);
            }
        }
    }

    GenericPoint2D<T> getExit() const {return exit;}

    void setExit(GenericPoint2D<T> newExit) {exit = newExit;}




    //--------------------
    bool inside(GenericPoint2D<T> pos) const {
        return pos.getX()>=0 && pos.getX()<nrow && pos.getY()>=0 && pos.getY()<ncol;
    }

    bool isWalled(GenericPoint2D<T> pos) const {
        if (!inside(pos)) return 1;
        int x = (int)pos.getX(), y = (int)pos.getY();
        return cells[x][y].getFlag();
    }

    bool valid(GenericPoint2D<T> pos) const {
        return inside(pos) && !isWalled(pos);
    }

    void addRobot(GenericRobot<T> *robot) {
        robots.push_back(robot);
    }

    virtual void robotGo() {
        for (int i=0;i<robots.size();i++) robots[i]->go(*this);
    }


    //--------------------
    void updatePrint() {
        std::vector<int> escapedRobots;
        escapedRobots.clear();

        for (int i=0;i<nrow;i++) {
            for (int j=0;j<ncol;j++ ) {
                if (GenericPoint2D<T>(i,j)==exit) {
                    cout << "X";

                    // if a robot has same position as exit
                    for (int k=0;k<robots.size();k++)
                        if (robots[k]->getPosition()==exit)
                            escapedRobots.push_back(k);

                    continue;
                }


                bool printed = 0;
                for (int k=0;k<robots.size();k++) {
                    GenericRobot<T> *r = robots[k];

                    if (r->getPosition()==GenericPoint2D<T>(i,j)) {
                        r->print();
                        printed = 1;
                        break;
                    }
                }

                if (!printed) {
                    if (isWalled(GenericPoint2D<T>(i,j))) cout << "1";
                    else cout << "0";
                }
            }
            cout << "\n";
        }

        for (int k=int(escapedRobots.size())-1;k>=0;k--) {
            cout << "\nA robot has escaped!!!\n";
            robots.erase(robots.begin() + escapedRobots[k]); // delete the robot from the matrix
        }
        escapedRobots.clear();

    }


    //-----------
    virtual void generateWalls() = 0;
};
