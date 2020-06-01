#include <iostream>
#include <time.h>
#include "GenericPoint2D.hpp"
#include "GenericCell.hpp"
#include "GenericCrazyRobot.hpp"
#include "GenericRandomMaze.hpp"
using std::cout;

typedef double T;
int main()
{
    Random::init(13); // set initial seed for randomization
    cout << "Maze layout\n\n";

    GenericMaze<T> *randomMaze = new GenericRandomMaze<T>(8,16,18,3);
    randomMaze->setExit(GenericPoint2D<T>(2,10));
    randomMaze->generateWalls();
    randomMaze->updatePrint();
    cout << "\n\n----------------------\n\n";


    cout << "Adding robots\n\n";
    randomMaze->addRobot(new GenericCrazyRobot<T>(GenericPoint2D<T>(3,4)));                                                       // red C
    randomMaze->addRobot(new GenericCrazyRobot<T>(GenericPoint2D<T>(7,12)));
    randomMaze->updatePrint();
    cout << "Press enter to continue\n";
    getchar();

    cout << "\n\n----------------------\n\n";
    while (true) {
        randomMaze->robotGo();
        randomMaze->updatePrint();
        cout << "\nPress enter to continue\n\n\n----------------------\n";
        getchar();
    }

    return 0;
}
