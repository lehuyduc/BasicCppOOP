#include <iostream>
#include "CrazyRobot.hpp"
#include "DownRobot.hpp"
#include "JumpingRobot.hpp"
#include "LeftRobot.hpp"
#include "RightRobot.hpp"
#include "SmartRobot.hpp"
#include "UpRobot.hpp"
#include "VerySmartRobot.hpp"
#include "SuperSmartRobot.hpp"
#include "RandomMaze.hpp"
using std::cout;


// in each Robot class, there's the print() function to print that Robot to the screen
// there's also the updatePrint() class in Maze and RandomMaze

// to make sure a robot does not go back to a covered cell,
// we use function isCovered(x,y) in class Robot.cpp
// Then, for each robot, it will ignore covered cells when it's looking for new cell to go.
// Look in files CrazyRobot.cpp, Up/Down/Left/RightRobot.cpp for examples
int main()
{
    Random::init(13); // set initial seed for randomization
    cout << "Maze layout\n\n";

    Maze *randomMaze = new RandomMaze(15,30,28,4);
    randomMaze->setExit(Point(1,29));
    randomMaze->generateWalls();
    randomMaze->updatePrint();
    cout << "\n\n----------------------\n\n";

    cout << "Adding robots\n\n";
        randomMaze->addRobot(new UpRobot(Point(3,29)));

    randomMaze->addRobot(new CrazyRobot(Point(3,3)));                                                       // red C
    randomMaze->addRobot(new CrazyRobot(Point(14,29)));
    randomMaze->addRobot(new LeftRobot(Point(3,24)));                                                       // yellow L
    randomMaze->addRobot(new RightRobot(Point(4,15)));                                                      // R
    randomMaze->addRobot(new UpRobot(Point(11,13)));                                                        // U
    randomMaze->addRobot(new DownRobot(Point(8,25)));                                                       // D
    randomMaze->addRobot(new JumpingRobot(Point(8,19),3));                                                  // purple J
    randomMaze->addRobot(new SmartRobot(Point(10,10)));                                                     // green S
    randomMaze->addRobot(new VerySmartRobot(Point(11,19),3,randomMaze->getNrow(),randomMaze->getNcol()));   // blue V
    randomMaze->addRobot(new SuperSmartRobot(Point(14,6)));
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
