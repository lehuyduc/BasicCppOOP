#include "circle.hpp"
#include <iostream>
#include <math.h>

double M_PI = 3.1416;

Circle::Circle(Point2D center, float radius) : Form()
{
    this->center = center;
    this->radius = radius;
}
Circle::~Circle()
{
}
Point2D Circle::getCenter() const
{
    return this->center;
}
float Circle::getRadius() const
{
    return this->radius;
}
void Circle::setCenter(Point2D center)
{
    this->center = center;
}
void Circle::setRadius(float radius)
{
    this->radius = radius;
}
void Circle::display()
{
   std::cout << "I'm a circle !" << std::endl;
   std::cout << "My center is ";
   this->center.display();
   std::cout << "My radius is " << this->radius << std::endl;
}
float Circle::area()
{
    return M_PI*this->radius*this->radius;
}
