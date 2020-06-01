#include "point.hpp"
#include "color.hpp"
#include <iostream>

int main(void)
{
    GenericPoint<int,int> P1(10,10);
    GenericPoint<int,float> P2(10,10.033);
    GenericPoint<char,char> P3('a','b');

    Color<int> red(1,0,0);
    Color<float> blue(0,0,255.0);
    GenericPoint<Color<int>,Color<float> > P4(red,blue);
    
    std::cout << P1 << std::endl;
    std::cout << P2 << std::endl;
    std::cout << P3 << std::endl;
    std::cout << P4 << std::endl;

}