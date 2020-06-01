#include "triangle.hpp"
#include <math.h>
#include <iostream>
using std::cout;

/*
 double dist() returns distance between two points.
 this function can be implemented in the Point2D class,
 or implemented as a friend function, or just like this

 This function should be in another file, such as utilities.cpp/hpp,
 but since the exercise is so short, I will just put it here.
*/
double dist(Point2D a, Point2D b) {
    double x1 = a.getX(), y1 = a.getY(), x2 = b.getX(), y2 = b.getY();
    double dx = x1-x2, dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}
//---------------------------


Triangle::Triangle(Point2D pt1, Point2D pt2, Point2D pt3) : Form() {
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
}

Triangle::~Triangle() {}

Point2D Triangle::getP1() const {return p1;}
Point2D Triangle::getP2() const {return p2;}
Point2D Triangle::getP3() const {return p3;}

void Triangle::setP1(Point2D p) {p1 = p;}
void Triangle::setP2(Point2D p) {p2 = p;}
void Triangle::setP3(Point2D p) {p3 = p;}


//----
void Triangle::display() {
    cout << "I'm a triangle\n";
    cout << "My points are:\n";
    p1.display();
    p2.display();
    p3.display();
}



float Triangle::area() {
    double a = dist(p1,p2), b = dist(p2,p3), c = dist(p3,p1);
    double s = double(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
