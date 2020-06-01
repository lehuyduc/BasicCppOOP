/*
 *  Sheep.cpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 04/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */
#include <iostream>
#include "Drawing.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Diamond.hpp"
#include "Ellipse.hpp"

const string NONE  = "\033[0m";
const string BLACK = "\033[3;30m";
const string RED   = "\033[3;31m";
const string GREEN = "\033[3;32m";
const string OLIVE = "\033[3;33m";
const string BLUE  = "\033[3;34m";
const string PURPLE= "\033[3;35m";
const string CYAN  = "\033[3;36m";
const string WHITE = "\033[3;37m";
/*
class DrawingTesting
{
  // NB: first pushed, last displayed (so on top)
public:
  static void Test() {
    Drawing drawing(NONE+" ", 80, 40);
    Rectangle r1(10, 10, 30, 10, RED+"r");
    drawing += r1;
    drawing.draw();
    /*
    Rectangle r2(20, 5, 30, 10, CYAN+"o" );
    drawing += r2;
    Circle c1(60, 24, 12, PURPLE+"c" );
    drawing += c1;
    Circle c2(10, 30, 15, BLUE+"%" );
    drawing += c2;
    Diamond d1(27, 25, 10, 7, WHITE+"d");
    drawing += d1;
    Ellipse e1(68, 6, 10, 6, GREEN+"e");
    drawing += e1;
    Graphic g1(40,1, OLIVE+"X"); // actually, it is a point!
    drawing += g1;
    drawing.draw();
    // wait user input
    getchar();
  }

  static void Sheep() {
    Drawing drawing( NONE+" ", 80, 40);
    // eyes
    Graphic p1(55, 21, BLUE+"O");
    Graphic p2(62, 21, BLUE+"O");
    drawing += p1;
    drawing += p2;
    // sun
    Circle c1(7, 35, 7, OLIVE+"s");
    drawing += c1;

    // sheep
    Diamond d1(53,22,2,2, WHITE+"@");
    Diamond d2(60,22,2,2, WHITE+"@");
    drawing += d1;
    drawing += d2;
    Rectangle r1(20, 10, 30, 10, WHITE+"@");
    Rectangle r2 (20, 0, 3, 10, WHITE+"@");
    Rectangle r3(47, 0, 3, 10, WHITE+"@");
    Rectangle r4(55, 18, 7, 1, RED+"=");
    Rectangle r5(15, 19, 5, 1, WHITE+"@");
    drawing += r1;
    drawing += r2;
    drawing += r3;
    drawing += r4;
    drawing += r5;
    Ellipse e1(20, 15, 3, 4, WHITE+"@");
    Ellipse e2(50, 15, 3, 4, WHITE+"@");
    Ellipse e3(58, 20, 8, 5, WHITE+"@");
    Ellipse e4(35, 19, 15, 2, WHITE+"@");
    Ellipse e5(31, 12, 12, 4, WHITE+"@");
    drawing += e1;
    drawing += e2;
    drawing += e3;
    drawing += e4;
    drawing += e5;
    drawing.draw();
    // wait user input
    getchar();
  }
};

*/


