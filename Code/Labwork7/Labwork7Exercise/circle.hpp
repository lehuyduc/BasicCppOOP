#ifndef CIRCLE_
#define CIRCLE_

#include "form.hpp"
#include "point2D.hpp"

class Circle : public Form
{
   public : 
      Circle(Point2D center, float radius);
      ~Circle();

      //Getters
      Point2D getCenter() const;
      float   getRadius() const;

      //Setters
      void setCenter(Point2D center);
      void setRadius(float radius);

      //Overriding method
      void display() override;

      //Overriding virtual method
      float area() override;

    private : 
        Point2D center;
        float radius;
};
#endif