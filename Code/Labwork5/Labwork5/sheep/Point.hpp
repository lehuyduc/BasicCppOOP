#pragma once

#include <iostream>
#include <cstdio>

struct Point {
    int x,y;
    Point() {}
    Point(int a,int b) {x=a; y=b;}
    Point(const Point& p) {x = p.x; y = p.y;}
};
