#include "rectangle.hpp"
#include <math.h>
#include <iostream>

Rectangle::Rectangle(Point2D min, Point2D max) : Form()
{
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
   std::cout << "I'm defined by two points : ";
   this->min.display();
   this->max.display();
}
float Rectangle::area()
{
    return fabs(this->min.getX()-this->max.getX())*fabs(this->min.getY()-this->max.getY());
}
      