#include <iostream>
#include <cmath>

// TODO: write the following file!
//       do not forget to add a constructor ;-)
#include "complex.hpp"

void check(const ComplexNumber&res, const ComplexNumber&truth, 
	   const std::string& operation = "unknown",
	   const double epsilon = 1e-6f) 
{
  if( fabs(res.m_real - truth.m_real)>=epsilon 
      || fabs(res.m_imaginary - truth.m_imaginary)>=epsilon ) {
    std::cerr<<"Error in "<<operation<<" operation ..."<<std::endl;
  }
  else {
    std::cout<<"Test "<<operation<<" operation passed"<<std::endl;
  }
}


void test_addition() {
  ComplexNumber a(1.0, 0.0), b(0.0, 1.0), c(1.0,1.0);
  check( addition( a, b ), c, std::string("addition") );
}



int main() {
  test_addition();
  // TODO: add new test functions ...
  
  return 0;
}
