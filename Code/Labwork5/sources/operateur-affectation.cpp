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
  Point& operator=( Point& p ) {
    m_x = p.m_x;
    m_y = p.m_y;
    cout<<"Point::operator=("<<m_x<<","<<m_y<<")"<<endl;
    return *this;
  }
};

class PointCol : public Point {
  short m_couleur;
public:
  PointCol(int a=0, int o=0, short couleur=1)
    : Point( a, o ) , m_couleur(couleur) {
    cout<<"PointCol("<<a<<","<<o<<","<<m_couleur<<")"<<endl; 
  };
   PointCol( PointCol& pc ) 
     : Point(pc), m_couleur(pc.m_couleur) {
     cout<<"CR PointCol("<<m_x<<","<<m_y<<","<<m_couleur<<")"<<endl; 
   };
  PointCol& operator=( PointCol& pc ) {
    Point::operator=( pc );
    m_couleur = pc.m_couleur;
    cout<<"PointCol::operator=("<<m_couleur<<")"<<endl;
    return *this;
  }
};

void fct ( PointCol ) {
  cout<< "fct()" << endl;
}

int main () {
  PointCol pc(2,4,6);
  PointCol pc2 = pc; // copy-constructor!
  pc2 = pc; // assignement operation
  fct( pc2 );
  return 0;
}
  
