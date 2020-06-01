#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
using std::cout;

const double A1[] = {0.0, 1.0, 2.0, 3.0, 4.0};
const double A2[] = {1.0, 1.0, 1.0, 1.0, 1.0};

class Vector {
    int m_n;
    double *m_v;
    Vector() {}

    void copy(const Vector&v)
    {
        m_n = v.m_n;
        m_v = new double[v.m_n];
        for(int i=m_n; i--; ) m_v[i] = v.m_v[i];
    }

    friend Vector add(const Vector& a, const Vector &b);
    friend Vector sub(const Vector& a, const Vector& b);
public:
      Vector(const unsigned n, const double*const v) {
        m_n = n;
        m_v = new double[n];
        for(int i=0;i<n;i++) m_v[i] = v[i];
    }

    Vector(const Vector& v) {
        copy(v);
    }

    ~Vector() {
        delete m_v;
        cout << "Destructing\n";
    }

    friend std::ostream& operator<<(std::ostream&, const Vector&);
};

Vector add(const Vector& a, const Vector& b) {
    if (a.m_n!=b.m_n) {cout << "Error 2 vectors\n"; exit(-1);}
    Vector res(a);
    Vector tmp(a);
    for (int i=0;i<a.m_n;i++)
        res.m_v[i] += b.m_v[i];
    return res;
}

Vector sub(const Vector& a, const Vector& b) {
    if (a.m_n!=b.m_n) {cout << "Error 2 vectors\n"; exit(-1);}
    Vector res(a);
    for (int i=0;i<a.m_n;i++)
        res.m_v[i] -= b.m_v[i];
    return res;
}

std::ostream& operator<<(std::ostream&os, const Vector&v) {
  os<<"{ ";
  for(unsigned i=0; i<v.m_n; ++i) {
    os << v.m_v[i] << " ";
  }
  os<<"}";
  return os;
}

int main()
{


    Vector a(5,A1), b(5,A2);
    Vector c = add(a,b);
    cout << c;

    int n;
    std::cin >> n;
    return 0;
}
