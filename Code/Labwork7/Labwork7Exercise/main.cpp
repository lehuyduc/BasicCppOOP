#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "ExceptionForm.hpp"
#include <vector>
#include <iostream>


int main()
{
    std::vector<Form*> forms;
    Rectangle *R = new Rectangle(Point2D(-1,-1),Point2D(1,1)); // new code in .cpp file
    Circle *C = new Circle(Point2D(0,0),1); // new code in .cpp file
    Square *S = new Square(Point2D(0,0),2); // new code in .cpp file
    Triangle *T = new Triangle(Point2D(0,0), Point2D(1,0), Point2D(0,1)); // new code in .cpp file

    forms.push_back(R);
    forms.push_back(C);
    forms.push_back(S);
    forms.push_back(T);

    for(unsigned int i=0;i<forms.size();i++){
       forms[i]->display();
       std::cout << "Area = " << forms[i]->area() << std::endl;
       std::cout << "\n";
    }

    std::cout << "\n--------------------------\n";
    try {
        R = new Rectangle(Point2D(-1,-1),Point2D(-1,-1));
    }
    catch (ExceptionForm e) {
        cout << e.what() << "\n";
    }

    try {
        C = new Circle(Point2D(0,0),0);
    }
    catch (ExceptionForm e) {
        cout << e.what() << "\n";
    }

    try {
        S = new Square(Point2D(0,0),-1);
    }
    catch (ExceptionForm e) {
        cout << e.what() << "\n";
    }

    try {
        T = new Triangle(Point2D(1,1), Point2D(0,0), Point2D(2,2));
    }
    catch (ExceptionForm e) {
        cout << e.what() << "\n";
    }

    try {
        T = new Triangle(Point2D(1,1), Point2D(1,1), Point2D(2,2));
    }
    catch (ExceptionForm e) {
        cout << e.what() << "\n";
    }
}
