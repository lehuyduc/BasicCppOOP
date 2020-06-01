#include <iostream>
using namespace std;

class Point {
  int m_x, m_y;
public:
  Point(int a=0, int o=0) : m_x(a), m_y(o) {
    cout<<"++++ Point("<<m_x<<","<<m_y<<")"<<endl;
  }
  ~Point() {
    cout<<"---- Point("<<m_x<<","<<m_y<<")"<<endl;
  }
  void print() const { cout<< "Point("<<m_x<<","<<m_y<<")" << endl; }
};

class Color {
  short m_color;
public:
  Color(short c=1) : m_color(c) {
    cout<<"++++ Color("<<m_color<<")"<<endl;
  }
  ~Color() {
    cout<<"---- Color("<<m_color<<")"<<endl;
  }
  void print() const { cout<< "Color("<<m_color<<")" << endl; }
};
  
class ColoredPoint : public Point, public Color {
public:
  ColoredPoint( int a=0, int o=0, short c=1 ) : Point( a, o ), Color( c ) {
    cout<<"++++ ColoredPoint("<<a<<","<<o<<","<<c<<")"<<endl;
  }
  ~ColoredPoint() { cout<<"---- ColoredPoint()" << endl; }
  void print() const {
    Point::print();  /// range resolution allows to select
    Color::print();  /// inherited methoc
  }
};

int main () {
  ColoredPoint cp( 1, 2, 3 );

  cp.print();

  return 0;
}
