#pragma once
#include <iostream>
#include "GenericPoint2D.hpp"
using std::cout;

template<class T>
class GenericCell {
    GenericPoint2D<T> loc; // location
    bool flag;

public:
    GenericCell<T>() {loc = GenericPoint2D<T>(); flag = 0;}
    GenericCell(GenericPoint2D<T> newp, bool newflag) {loc = newp; flag = newflag;}
    GenericCell(const T &b) {loc = b.loc; flag = b.flag;}

    GenericPoint2D<T> getLoc() const {return loc;}
    bool getFlag() const {return flag;}

    void setLoc(GenericPoint2D<T> newloc) {loc = newloc;}
    void setFlag(bool newflag) {flag = newflag;}

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const GenericCell<U> &c);
};

template<class T>
std::ostream& operator<<(std::ostream& os, const GenericCell<T> &c) {
    os << c.loc << " " << c.flag;
    return os;
}
