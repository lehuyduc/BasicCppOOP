#include <iostream>
using namespace std;
// ================================================================
class A {
  int na;
 public:
 A( int nn=1 ) : na( nn ) {    cout << "$$creates object A " << na << endl;  }
};
// ================================================================
class B : public virtual A {
  float xb ;
 public:
  B( float xx=0.f ) : xb( xx ) {    cout << "$$creates object B " << xb << endl;  }
};
// ================================================================
class C : public virtual A {
  int nc;
public:
  C( int nn=2 ) : A( 2*nn+1 ), nc( nn ) {    cout << "$$creates object C " << nc << endl;  }
};
// ================================================================
class D : public B, public C {
  int nd;
 public:
  D(int n1, int n2, float x) : A(2*n1+1), B(x), C(n1), nd(n2) { cout<<"$$creates object D "<<nd<<endl; }
};
// ================================================================
int main() {
  D d( 10, 20, 5.f );
  return 0;
}

// without virtual: A1 B5 A21 C10 D20
// with virtual: A21, B5, C10, D20
