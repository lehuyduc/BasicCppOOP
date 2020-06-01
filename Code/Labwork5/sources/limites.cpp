#include <iostream>
using namespace std;

class Point {
protected:
  int m_x, m_y;
public:
  Point( int a=0, int o=0) : m_x(a), m_y(o) {};
  Point( const Point& p ) : m_x(p.m_x), m_y(p.m_y) {};
  Point &operator+( const Point& p ) {
    m_x = p.m_x;
    m_y = p.m_y;
    return (*this);
  }
  friend int equals ( const Point&, const Point& );
  void display() { cout<<"Point("<<m_x<<","<<m_y<<")"<<endl; }
};

int equals ( const Point& a, const Point& b ) {
  return a.m_x == b.m_x && a.m_y == b.m_y;
}

class PointCol : public Point {
  short _color;
public:
  PointCol( int a=0, int o=0, short c=1 ) : Point( a, o ), _color(c) {};
  PointCol( const PointCol& p ) : Point( p ), _color(p._color)     {};
};

int main () {
  PointCol a(2,5,3), b(2,5,9);

  Point c;

  if ( equals( a, b ) ) cout<<"a equals avec b"<<endl;
  else cout<<"a et b are different"<<endl;
  if ( equals( a, c ) ) cout<<"a equals avec c"<<endl;
  else cout<<"a et c are different"<<endl;

  c  = a+b;    c.display();
  return 0;
}
