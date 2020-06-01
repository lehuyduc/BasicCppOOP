#include <iostream>
using namespace std;
template< typename T > class Point {
  T m_x, m_y ;
public:
  Point( T a=0, T o=0 ) : m_x(a), m_y(o) {}
  void affiche() { cout<<"Point("<<m_x<<","<<m_y<<")"<<endl; }
};
class PointCol_int : public Point<int> {
  short m_couleur;
public:
  PointCol_int( int a=0, int o=0, short couleur=1 ) : Point<int>( a, o ), m_couleur(couleur) {}
  void affiche() {
    Point<int>::affiche();
    cout<<"\tcouleur : "<<m_couleur<<endl;
  }
};

int main() {
  Point<float> pf ( 3.5, 2.8 ); pf.affiche();
  PointCol_int p ( 3, 5, 9 );   p.affiche();
  return 0;
}
