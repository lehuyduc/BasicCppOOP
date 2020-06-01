#include <iostream>
using namespace std;

template< typename T > class Point {
  T m_x, m_y ;
public:
  Point( T a=0, T o=0 ) : m_x(a), m_y(o) {}
  void affiche() { cout<<"Point("<<m_x<<","<<m_y<<")"<<endl; }
};

template< typename T > class PointCol : public Point<T> {
  short _couleur;
public:
  PointCol( T a=0, T o=0, short couleur=1 ) : Point<T>( a, o ), _couleur(couleur) {}
  void affiche() {
    Point<T>::affiche();
    cout<<"\tcouleur : "<<_couleur<<endl;
  }
};

int main() {
  Point<float> pf ( 3.5, 2.8 ); pf.affiche();
  PointCol<int> p ( 3, 5, 9 );  p.affiche();
  return 0;
}
