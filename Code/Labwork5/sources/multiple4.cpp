#include <iostream>
using namespace std;
///
class Point {
protected:
  int m_x, m_y;
public:
  Point( int abs=0, int ord=0) : m_x(abs), m_y(ord) {
    cout << "++++++ Point(" << abs << "," << ord << ")" << endl; 
    //std::cout<<"size = "<<sizeof(*this)<<std::endl; 
  }
  void print() { cout << "Coordinates: " << m_x << " and " << m_y << endl; }
};
///
class Color {
  short m_color;
public:
  Color( short color=1 ) : m_color( color ) {
    cout << "++++ Color(" << m_color << ")" << endl;  
    //std::cout<<"size = "<<sizeof(*this)<<std::endl;
  }
  void print() { cout << "Color : " << m_color << endl; }
};
///
class Mass {
  int m_mass;
public:
  Mass( int m=100 ) : m_mass( m ) {
    cout << "++++ Mass(" << m_mass << ")" << endl;
    //std::cout<<"size = "<<sizeof(*this)<<std::endl;
  }
  void print () { cout << "Mass: " << m_mass << endl;}
};

class ColoredPoint : public virtual Point, public Color {
public:
  ColoredPoint( int abs, int ord, int cl ) : Point(abs, ord), Color( cl ) {
    cout << "++ ColoredPoint(" << m_x << "," << m_y << "," << cl << ")" << endl;
    //std::cout<<"size = "<<sizeof(*this)<<std::endl;
  }
  ColoredPoint( int cl ) : Color( cl ) { cout << "++ ColoredPoint(" << cl << ")" << endl;  
    //std::cout<<"size = "<<sizeof(*this)<<std::endl;
  }
  void print() {    Point::print();    Color::print(); }
};
///
class MassPoint : public virtual Point, public Mass {
public:
  MassPoint( int abs, int ord, int ms ) : Point(abs, ord), Mass( ms ) {
    cout << "++ MassPoint(" << m_x << "," << m_y << "," << ms << ")" << endl; 
    //std::cout<<"size = "<<sizeof(*this)<<std::endl;  
  }
  void print() {    Point::print();    Mass::print(); }
};
///
class ColoredMassPoint : public ColoredPoint, public MassPoint {
public:
  ColoredMassPoint( int abs, int ord, short c, int m ) 
    : Point( abs, ord ), ColoredPoint( c ), MassPoint( abs, ord, m ) {
    cout << "ColoredMassPoint(" << abs << "," << ord << "," << c << "," << m << ")" << endl; 
    //    std::cout<<"size = "<<sizeof(*this)<<std::endl;
  }
  void print() {    Point::print();    Color::print();    Mass::print();  }
};
///
int main () {
  cout << "*****************" << endl;  ColoredPoint     p( 3, 9, 2 );        p.print();
  cout << "*****************" << endl;  MassPoint        mp( 12, 25, 100 );   mp.print();
  cout << "*****************" << endl;  ColoredMassPoint cmp( 2, 5, 10, 20 ); cmp.print();
  return 0;
}

// #include <iostream>
// using namespace std;

// class Point {
// protected:
//   int _x, _y;
// public:
//   Point( int abs=0, int ord=0) : _x(abs), _y(ord) {
//     cout << "++++++ Point(" << abs << "," << ord << ")" << endl;
//   }
//   void affiche() {
//     cout << "Coordonnees : " << _x << " et " << _y << endl;
//   }
// };

// class Couleur {
//   short _couleur;
// public:
//   Couleur( short couleur=1 ) : _couleur( couleur ) {
//     cout << "++++ Couleur(" << _couleur << ")" << endl;
//   }
//   void affiche() {
//     cout << "Couleur : " << _couleur << endl;
//   }
// };

// class Masse {
//   int _masse;
// public:
//   Masse( int m=100 ) : _masse( m ) {
//     cout << "++++ Masse(" << _masse << ")" << endl;
//   }
//   void affiche () {
//     cout << "Masse : " << _masse << endl;
//   }
// };

// class PointCoul : public virtual Point, public Couleur {
// public:
//   PointCoul( int abs, int ord, int cl ) : Couleur( cl ) {
//     _x = abs;
//     _y = ord;
//     cout << "++ PointCoul(" << _x << "," << _y << "," << cl << ")" << endl;
//   }
//   PointCoul( int cl ) : Couleur( cl ) {
//     cout << "++ PointCoul(" << cl << ")" << endl;
//   }
//   void affiche() {
//     Point::affiche();
//     Couleur::affiche();
//   }
// };

// class PointMasse : public virtual Point, public Masse {
// public:
//   PointMasse( int abs, int ord, int ms ) : Masse( ms ) {
//     _x = abs;
//     _y = ord;
//     cout << "++ PointMasse(" << _x << "," << _y << "," << ms << ")" << endl;
//   }
//   void affiche() {
//     Point::affiche();
//     Masse::affiche();
//   }
// };

// class PointCoulMasse : public PointCoul, public PointMasse {
// public:
//   PointCoulMasse( int abs, int ord, short c, int m ) 
//     : Point( abs, ord ), PointCoul( c ), PointMasse( abs, ord, m ) 
//   {
//     cout << "PointCoulMasse(" << abs << "," << ord << "," << c << "," << m << ")" << endl;
//   }
//   void affiche() {
//     Point::affiche();
//     Couleur::affiche();
//     Masse::affiche();
//   }
// };

// int main () {
//   cout << "*****************" << endl;
//   PointCoul   p( 3, 9, 2 ); p.affiche();
//   cout << "*****************" << endl;
//   PointMasse  pm( 12, 25, 100 ); pm.affiche();
//   cout << "*****************" << endl;
//   PointCoulMasse pcm( 2, 5, 10, 20 ); pcm.affiche();
//   return 0;
// }
    
