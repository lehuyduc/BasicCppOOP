#include <iostream>
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(int a,int b) {x = a; y = b;}

Point::Point(const Point& b) {x = b.x; y = b.y;}

int Point::getX() const {return x;}
int Point::getY() const {return y;}

void Point::setX(int t) {x = t;}
void Point::setY(int t) {y = t;}

Point& Point::operator=(const Point& b) {
    this->x = b.x;
    this->y = b.y;
    return (*this); // teacher Aveneau code operator= like this
}

bool Point::operator==(const Point& b) const {
    return x==b.x && y==b.y;
}

bool Point::operator!=(const Point& b) const {
    return x!=b.x || y!=b.y;
}

std::ostream& operator<<(std::ostream&os, const Point& p) {
  os << p.x << " " << p.y;
  return os;
}
