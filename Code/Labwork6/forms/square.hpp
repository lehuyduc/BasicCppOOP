#ifndef SQUARE_
#define SQUARE_

#include "form.hpp"
#include "point2D.hpp"

class Square : public Form
{
    private :
        Point2D center;
        double side;

   public :
      Square(Point2D, double);
      ~Square();

      //Getters
      Point2D getCenter() const;
      double getSide() const;

      //Setters
      void setCenter(Point2D);
      void setSide(double);

      //Overriding method
      void display() override;

      //Overriding method
      float area() override;
};
#endif
