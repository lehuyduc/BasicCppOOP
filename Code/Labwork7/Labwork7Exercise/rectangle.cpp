#include "rectangle.hpp"
#include <math.h>
#include <iostream>
#include "ExceptionForm.hpp"

Rectangle::Rectangle(Point2D min, Point2D max) : Form()
{
    if (min==max)   // we can write this without overloading operator == because class Point2D doesn't have dynamic variable
        throw ExceptionForm("Rectangle error: 2 same point");
    this->min = min;
    this->max = max;
}
Rectangle::~Rectangle()
{
}
Point2D Rectangle::getMin() const
{
    return this->min;
}
Point2D Rectangle::getMax() const
{
    return this->max;
}

void Rectangle::setMin(Point2D min)
{
    this->min = min;
}
void Rectangle::setMax(Point2D max)
{
    this->max = max;
}
void Rectangle::display()
{
   std::cout << "I'm a rectangle !" << std::endl;
   std::cout << "I'm defined by two points : \n";
   this->min.display();
   this->max.display();
}
float Rectangle::area()
{
    return fabs(this->min.getX()-this->max.getX())*fabs(this->min.getY()-this->max.getY());
}
