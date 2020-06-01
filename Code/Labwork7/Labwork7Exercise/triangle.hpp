#ifndef TRIANGLE_
#define TRIANGLE_

#include "form.hpp"
#include "point2D.hpp"

class Triangle : public Form{
private:
    Point2D p1, p2, p3;
    Triangle() {}


public:
    Triangle(Point2D, Point2D, Point2D);
    ~Triangle();

    Point2D getP1() const;
    Point2D getP2() const;
    Point2D getP3() const;

    void setP1(Point2D);
    void setP2(Point2D);
    void setP3(Point2D);

    //---
    void display() override;

    float area() override;


};
#endif
