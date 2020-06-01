#include <iostream>
int    x = 1;
double d = 1.;
using namespace std;

// TODO: fix the problems
namespace B {
    void f(double a);
}

namespace A /// definition
{ /// of named space A
  int x = 2;
  double d = 2.;
  void f(int a) {
    cout<<"A::f("<<a<<")"<<endl;
    cout<<"-> ";
    B::f((double)a);
  }
}

namespace B /// definition
{ /// of named space B
  int x = 3;
  double d = 3.;
  void f(double a) {
    cout<<"B::f("<<a<<")"<<endl;
  }

  void g(int a) {
    cout<<"B::g() call ";
    A::f(a);
  }
}

int main ()
{
  A::f(A::x);    // f from A, x from A
  A::f(B::x);    // f from A, x from B
  B::f(A::d); // f from B, d from A
  B::f(B::d); // f from B, d from B
  A::f(::x);     // f from A, x global
  B::f(::d);  // f from B, d global

  B::g(42);
  return 0;
}
