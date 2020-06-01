#ifndef POINT_
#define POINT_

template <class T, class U>
class GenericPoint
{
    private : 
        T x;
        U y;
    public :
        GenericPoint(T x=0, U y=0)
        {
            this->x = x;
            this->y = y;
        }
        GenericPoint(const GenericPoint &P)
        {
            this->x = P.x;
            this->y = P.y;
        }
        ~GenericPoint(){}

        T getX() const { return x;}
        U getY() const { return y;}

        void setX(const T x){ this->x = x;}
        void setY(const U y){ this->y = y;}
};
#endif