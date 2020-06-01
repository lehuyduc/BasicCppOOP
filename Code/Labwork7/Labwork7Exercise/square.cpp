
#include "square.hpp"
#include <math.h>
#include <iostream>
#include "ExceptionForm.hpp"
using std::cout;

Square::Square(Point2D center, double side) : Form()
{
    if (side <= 0)
        throw ExceptionForm("Square error: side length <= 0");
    this->center = center;
    this->side = side;
}
Square::~Square()
{
}
Point2D Square::getCenter() const
{
    return this->center;
}
double Square::getSide() const
{
    return this->side;
}

void Square::setCenter(Point2D center)
{
    this->center = center;
}
void Square::setSide(double side)
{
    this->side = side;
}
void Square::display()
{
   cout << "I'm a square!" << std::endl;
   cout << "My center is: \n";
   this->center.display();
   cout << "The length of my side is " << side << "\n";
}
float Square::area()
{
    return side*side;
}
