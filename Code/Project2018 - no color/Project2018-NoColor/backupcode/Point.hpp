#pragma once
#include <iostream>
#include <ostream>
using std::cout;

class Point {
    int x,y;

public:
    Point();
    Point(int a,int b);
    Point(const Point& b);

    int getX() const;
    int getY() const;

    void setX(int t);
    void setY(int t);

    Point& operator= (const Point& b);

    bool operator==(const Point& b) const;

    bool operator!=(const Point& b) const;

    friend std::ostream& operator<<(std::ostream&, const Point&);
};
