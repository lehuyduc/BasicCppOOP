#ifndef RECTANGLE_
#define RECTANGLE_

#include "form.hpp"
#include "point2D.hpp"

class Rectangle : public Form
{
   public : 
      Rectangle(Point2D min, Point2D max);
      ~Rectangle();

      //Getters
      Point2D getMin() const;
      Point2D getMax() const;

      //Setters
      void setMin(Point2D min);
      void setMax(Point2D max);

      //Overriding method
      void display() override;

      //Overriding method
      float area() override;
      
    private : 
        Point2D min;
        Point2D max;
};
#endif