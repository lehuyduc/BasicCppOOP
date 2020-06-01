#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class O {
public:
  O()  { cout << "++++ O()" << endl; }
  ~O() { cout << "---- O()" << endl; }
};

////////////////////////////////////////////////////////////////
class A : public O {
protected:
  int m_x;
public:
  A(int x=0) : O(), m_x(x) {
    cout<< "++++ A("<< m_x << ")" << endl;
  }
  ~A() {
    cout<< "---- A("<< m_x << ")" << endl;
  }
};

////////////////////////////////////////////////////////////////
class B : public virtual A {
public:
  B(int x=0) {
    m_x = x + 10; // more direct calls to constructor - plus d'appel constructeur direct !
    cout<< "++++ B("<< A::m_x << ")" << endl;
  }
  ~B() {
    cout<< "---- B("<< A::m_x << ")" << endl;
  }
};

////////////////////////////////////////////////////////////////
class C : virtual public A {
public:
  C(int x=0) {
    m_x = x+100;
    cout<< "++++ C("<< A::m_x << ")" << endl;
  }
  ~C() {
    cout<< "---- C("<< A::m_x << ")" << endl;
  }
};

////////////////////////////////////////////////////////////////
class D : public B, public C {
public:
  D(int x=0) : A(x), B(x), C(x) {
    cout<< "++++ D("<< B::m_x << "," << C::m_x << ")" << endl;
  }
  ~D() {
    cout<< "---- D("<< B::m_x << "," << C::m_x << ")" << endl;
  }
};

////////////////////////////////////////////////////////////////
int main () {
  D(3);
  return 0;
}
