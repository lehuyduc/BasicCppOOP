#include <iostream>
#include "point.h"

class PointCol : public Point {
  short m_color;
public:
  void colored( short couleur ) { m_color = couleur; }
  void print() ;
  void init( int, int, short );
};

void PointCol::print() {
  Point::print();
  std::cout<<"\tet ma couleur est "<<m_color<<std::endl;
}
void PointCol::init( int x, int y, short couleur ) {
  Point::init( x, y );
  m_color = couleur;
}

int main () {
  PointCol p;
  p.init( 10, 20, 5 ); p.print();
  p.Point::print();
  p.move( 2, 4 );         p.print();
  p.colored( 2 );             p.print();
  return 0;
}
