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
  //TODO
}
