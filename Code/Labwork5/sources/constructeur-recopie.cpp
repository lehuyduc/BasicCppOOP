#include <iostream>

using namespace std;

class Point {
protected:
  int m_x, m_y;
public:
  Point( int a=0, int o=0 ) : m_x(a), m_y(o) { 
    cout<<"Point("<<a<<","<<o<<")"<<endl; 
  }
  Point( Point& p ) : m_x(p.m_x), m_y(p.m_y) {
    cout<<"CR Point("<<m_x<<","<<m_y<<")"<<endl; 
  }
};

class PointCol : public Point {
  short _couleur;
public:
  PointCol(int a=0, int o=0, short couleur=1)
    : Point( a, o ) , _couleur(couleur) {
    cout<<"PointCol("<<a<<","<<o<<","<<_couleur<<")"<<endl; 
  };
  PointCol( PointCol& pc ) 
    : Point(pc), _couleur(pc._couleur) {
    cout<<"CR PointCol("<<m_x<<","<<m_y<<","<<_couleur<<")"<<endl; 
  };
};

void fct ( PointCol pc ) {
  cout<< "fct()" << endl;
}

int main () {
  PointCol pc(2,4,6);
  fct( pc );
  return 0;
}
  
