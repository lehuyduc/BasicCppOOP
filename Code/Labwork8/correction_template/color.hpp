#ifndef COLOR_
#define COLOR_
#include <iostream>

template <class T>
class Color
{
    private :
        T r,g,b;
    public :
        Color(T r=0, T g=0, T b=0)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        ~Color(){}

        friend std::ostream& operator <<(std::ostream &out, const Color& C)
        {
            out << "r = " << C.r << " g = " << C.g << " b = " << C.b ;
            return out;
        }
};
#endif