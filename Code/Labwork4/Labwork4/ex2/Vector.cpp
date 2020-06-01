#include "Vector.hpp"

std::ostream& operator<<(std::ostream&os, const Vector&v) {
  os<<"{ ";
  for(unsigned i=0; i<v.m_n; ++i) {
    os << v.m_v[i] << " ";
  }
  os<<"}";
  return os;
}


Vector operator*(const double& d, const Vector&v) {
    Vector res(v);
    for (int i=0;i<v.m_n;i++)
        res.m_v[i] *= d;
    return res;
    // easier way to right, but slower: return Vector(v)*d;
}
