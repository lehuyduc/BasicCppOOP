#include "point2D.hpp"
#include <iostream>

Point2D::Point2D()
{
   x = y = 0;
}
Point2D::Point2D(float x, float y)
{
   this->x = x;
   this->y = y;
}
Point2D::Point2D(const Point2D &P)
{
   this->x = P.x;
   this->y = P.y;
}
Point2D::~Point2D()
{
}
float Point2D::getX() const
{
   return this->x;
}
float Point2D::getY() const
{
   return this->y;
}
void Point2D::setX(float x)
{
   this->x = x;
}
void Point2D::setY(float y)
{
   this->y = y;
}
void Point2D::display()
{
   std::cout << "x = " << this->x << " y = " << this->y << std::endl;
}


// // new code here
bool Point2D::operator==(const Point2D& p) const {
    return (abs(x-p.x)<=0.0001 && abs(y-p.y)<=0.0001); // float == float is generally bad practice
}


bool collinear(const Point2D& pt1, const Point2D& pt2, const Point2D& pt3) {
    double dx1 = pt2.x - pt1.x, dy1 = pt2.y - pt1.y;
    double dx2 = pt3.x - pt1.x, dy2 = pt3.y - pt1.y;
    return (abs(dy1*dx2 - dy2*dx1)<=0.00001); // dy1/dx1 = dy2/dx2 -> dy1*dx2 = dy2*dx1 -> 3 collinear points
}
