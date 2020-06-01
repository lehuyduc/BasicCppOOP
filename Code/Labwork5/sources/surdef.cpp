#include <iostream>

using namespace std;

class A {
 public:
  void f(int )  { cout<<"A::f(int)\n";  }
  void f(char)  { cout<<"A::f(char)\n"; }
  void g(int )  { cout<<"A::g(int)\n";  }
};
class B : public A {
 public:
  void f(int)       { cout<<"B::f(int)\n"; }
  void g(int, int ) { cout<<"B::g(int,int)\n"; }
  using A::g;
};


int main () {
  int n=42; char c='o'; B b;
  b.f(n);   // call B::f(int);
  b.f(c);   // call B::f(int);
  b.g(n);   // compilation error ...
  return 0; // solution: "using A::g;"
}
