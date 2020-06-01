#ifndef FORM_
#define FORM_

class Form 
{
   public :

     // Constructors
     Form();

     // Destructor
     ~Form();

     virtual void display() = 0;

     virtual float area() = 0;

};
#endif