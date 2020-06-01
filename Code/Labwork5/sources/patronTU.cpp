#include <iostream>
using namespace std;

template< typename T > class Point {
  T m_x, m_y ;
public:
  Point( T a=0, T o=0 ) : m_x(a), m_y(o) {}
  void affiche() { cout<<"Point("<<m_x<<","<<m_y<<")"<<endl; }
};

template< typename T, typename U > class PointCol : public Point<T> {
  U m_couleur;
public:
  PointCol( T a=0, T o=0, U couleur=1 ) : Point<T>( a, o ), m_couleur(couleur) {}
  void affiche() {
    Point<T>::affiche();
    cout<<"\tcolor : "<<m_couleur<<endl;
  }
};

int main() {
  Point<float> pf ( 3.5, 2.8 );       pf.affiche();
  PointCol<int,short> p ( 3, 5, 9 );  p.affiche();
  return 0;
}
