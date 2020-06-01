#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include <vector>
#include <iostream>

int main()
{
   std::vector<Form*> forms;
   Rectangle *R = new Rectangle(Point2D(-1,-1),Point2D(1,1)); // the same code
   Circle *C = new Circle(Point2D(0,0),1); // the same code
   Square *S = new Square(Point2D(0,0),2); // new code
   Triangle *T = new Triangle(Point2D(0,0), Point2D(1,0), Point2D(0,1)); // we can handle invalid inputs
                                                                         // in next lecture

   forms.push_back(R);
   forms.push_back(C);
   forms.push_back(S);
   forms.push_back(T);

   for(unsigned int i=0;i<forms.size();i++){
       forms[i]->display();
       std::cout << "Area = " << forms[i]->area() << std::endl;
       std::cout << "\n";
   }
}
