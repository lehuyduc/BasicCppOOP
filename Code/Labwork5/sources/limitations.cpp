#include <iostream>
using namespace std;

class Point {
protected:
  int m_x, m_y;
public:
  Point( int a=0, int o=0 ) : m_x(a), m_y(o) {}
  void display() const {
    cout<< "Point(" << m_x << "," << m_y << ")" <<endl;
  }
};

class PointCol : public Point {
  short _color;
public:
  PointCol( int a=0, int o=0, short color=1 ) : Point( a, o ), _color( color ) {}
  void display() const {
    cout<< "PointCol(" << m_x << "," << m_y << "," << _color << ")" <<endl;
  }
};

int main () {
  Point p( 3, 5 );        Point *adp = &p;
  PointCol pc( 8, 6, 2 ); PointCol *adpc = &pc;
  adp->display(); adpc->display();
  cout<< "--------------------------------" <<endl;
  adp = adpc;
  adp ->display();
  adpc->display();

  return 0;
}
