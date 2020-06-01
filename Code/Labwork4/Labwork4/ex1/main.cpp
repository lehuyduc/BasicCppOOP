#include <iostream>
#include "Vector.hpp"

void testVector() {
  const double array[] = {0.0, 1.0, 2.0, 3.0, 4.0};
  Vector a(5, array), b(5, 1.0);
  Vector c(a+b);
  std::cout<<"a="<<a<<std::endl;
  std::cout<<"b="<<b<<std::endl;
  std::cout<<"c="<<c<<std::endl;

  if( !(a == a) )
    std::cerr<<"operator== does not works"<<std::endl;
  if( c-b != a ) {
    std::cerr<<"operator+ and operator- are not consistent"<<std::endl;
    std::cout<<(c-b)<<std::endl;
  }
  if( 6.0*5.0/2.0 != b * c ) {
    std::cerr<<"operator* does not work"<<std::endl;
    std::cout<<(b*c)<<std::endl;
  }

    int n;
  std::cin >> n;

}

int main() {
  testVector();
  return 0;
}
