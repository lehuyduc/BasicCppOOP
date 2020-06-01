#pragma once
#include <iostream>
#include <ostream>
using std::cout;

template<class T>
class GenericPoint2D {
    T x,y;
    // we do not want people to use empty constructor

public:
    GenericPoint2D<T>() {};
    GenericPoint2D(T a,T b) {x = a; y = b;}
    GenericPoint2D(const GenericPoint2D& b) {x = b.x;  y = b.y;};

    T getX() const {return x;};
    T getY() const {return y;};

    void setX(T t) {x = t;};
    void setY(T t) {y = t;};

    GenericPoint2D& operator= (const GenericPoint2D& b) {
        if (this!=&b) {
            x = b.x;
            y = b.y;
        }
        return *this;
    };

    bool operator==(const GenericPoint2D& b) const {
        return x==b.x && y==b.y;
    };

    bool operator!=(const GenericPoint2D& b) const {
        return x!=b.x || y!=b.y;
    };

    template<class U>
    friend std::ostream &operator<<(std::ostream& os, const GenericPoint2D<U> p);
};

template<class T>
std::ostream& operator<<(std::ostream& os,  GenericPoint2D<T> p) {
    os << p.x << " " << p.y;
    return os;
}
