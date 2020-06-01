#include <iostream>
#include "Point.h"
using std::cout;

struct direction;

double norme(direction v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

struct direction {
    double x,y;
    direction() {}
    direction(double a, double b) {x = a/norme(a,b); y = b/norme(a,b);}
};

class Line {
    Point start;
    direction nv;

    Line(Point a, Point b) {

    }
};
