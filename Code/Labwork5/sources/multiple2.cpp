#include <iostream>
using namespace std;

class A {
protected:
  int m_x;
public:
  A(int x=0) : m_x(x) {
    cout<< "++++ A("<< m_x << ")" << endl;
  }
  ~A() {
    cout<< "---- A("<< m_x << ")" << endl;
  }
};

class B : protected A {
public:
  B(int x=0) : A(x + 10) {
    cout<< "++++ B("<< A::m_x << ")" << endl;
  }
  ~B() {
    cout<< "---- B("<< A::m_x << ")" << endl;
  }
};

class C : protected A {
public:
  C(int x=0) : A(x + 100) {
    cout<< "++++ C("<< A::m_x << ")" << endl;
  }
  ~C() {
    cout<< "---- C("<< A::m_x << ")" << endl;
  }
};

class D : protected B, protected C {
public:
  D(int x=0) : B(x), C(x) {
    cout<< "++++ D("<< B::m_x << "," << C::m_x << ")" << endl;
  }
  ~D() {
    cout<< "---- D("<< B::m_x << "," << C::m_x << ")" << endl;
  }
};

int main () {
  D(3);
  return 0;
}
