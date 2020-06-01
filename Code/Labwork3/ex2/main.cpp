#include <iostream>
#include "Complex.hpp"
using std::cout;

void testCartesian() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing cartesian\n";
  const Complex a = Complex::fromCartesian(1.0, 0.0);
  std::cout <<"a="<<a.printCartesian()<<std::endl;
  if (a.getReal() != 1.0) std::cerr << a.getReal() << "-> bad real value!!"<<std::endl;
  if( a.getImaginary() != 0.0 ) std::cerr<< a.getImaginary() << "-> bad imag value!!"<<std::endl;
  const Complex b = Complex::fromCartesian(0.0, 1.0);
  std::cout <<"b="<<b.printCartesian()<<std::endl;
  if( b.getReal() != 0.0 ) std::cerr<<"-> bad real value!!"<<std::endl;
  if( b.getImaginary() != 1.0 ) std::cerr<<"-> bad imag value!!"<<std::endl;
  const Complex c = Complex::fromCartesian(1.0, 1.0);
  std::cout <<"c="<<c.printCartesian()<<std::endl;
  if( c.getReal() != 1.0 ) std::cerr<<"-> bad real value!!"<<std::endl;
  if( c.getImaginary() != 1.0 ) std::cerr<<"-> bad imag value!!"<<std::endl;
  const Complex d = Complex::fromCartesian(-1.0, -1.0);
  std::cout <<"d="<<d.printCartesian()<<std::endl;
  if( d.getReal() != -1.0 ) std::cerr<<"-> bad real value!!"<<std::endl;
  if( d.getImaginary() != -1.0 ) std::cerr<<"-> bad imag value!!"<<std::endl;
}


void testPolar() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing polar\n";
  const Complex a = Complex::fromPolar(1.0, 0.0);
  std::cout <<"a="<<a.printPolar()<<std::endl;
  if( a.getMagnitude() != 1.0 ) std::cerr<<"-> bad magnitude!!"<<std::endl;
  if( a.getAngle() != 0.0 ) std::cerr<<"-> bad angle!!"<<std::endl;
  // warning: magnitude 0 leads to number 0 ... so no angle
  const Complex b = Complex::fromPolar(0.0, 1.0);
  std::cout <<"b="<<b.printPolar()<<std::endl;
  if( b.getMagnitude() != 0.0 ) std::cerr<<"-> bad magnitude!!"<<std::endl;
  //if( b.getAngle() != 1.0 ) std::cerr<<"-> bad angle!!"<<std::endl;
  const Complex c = Complex::fromPolar(1.0, 1.0);
  std::cout <<"c="<<c.printPolar()<<std::endl;
  if( c.getMagnitude() != 1.0 ) std::cerr<<"-> bad magnitude!!"<<std::endl;
  if( c.getAngle() != 1.0 ) std::cerr<<"-> bad angle!!"<<std::endl;
  // warning: negative magnitude has no sens
  const Complex d = Complex::fromPolar(1.0, -1.0);
  std::cout <<"d="<<d.printPolar()<<std::endl;
  if( d.getMagnitude() != 1.0 ) std::cerr<<"-> bad magnitude!!"<<std::endl;
  if( d.getAngle() != -1.0 ) std::cerr<<"-> bad angle!!"<<std::endl;
}


void testAddition() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing addition\n";
  const Complex a = Complex::fromCartesian(0.0, 1.0);
  const Complex b = Complex::fromCartesian(1.0, -1.0);
  const Complex c = a.add(b);
  std::cout <<a.printCartesian()<<" + "<<b.printCartesian()<<" = "<<c.printCartesian()<<std::endl;
  const Complex expected = Complex::fromCartesian(1.0, 0.0);
  if( !c.equals(expected) ) std::cerr<<"->bad addition result!!"<<std::endl;
}

void testSubtraction() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing subtraction\n";
  const Complex a = Complex::fromCartesian(1.0, 2.0);
  const Complex b = Complex::fromCartesian(1.0, -1.0);
  const Complex c = a.sub(b);
  std::cout <<a.printCartesian()<<" - "<<b.printCartesian()<<" = "<<c.printCartesian()<<std::endl;
  const Complex expected = Complex::fromCartesian(0.0, 3.0);
  if( !c.equals(expected) ) std::cerr<<"->bad subtraction result!!"<<std::endl;
}

void testMultiplication() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing multiplication\n";
  const Complex a = Complex::fromCartesian(2.0, 1.0);
  const Complex b = Complex::fromCartesian(-3.0, 4.0);
  const Complex c = a.mult(b);
  std::cout <<a.printCartesian()<<" * "<<b.printCartesian()<<" = "<<c.printCartesian()<<std::endl;
  const Complex expected = Complex::fromCartesian(2.*(-3.0)-1.0*4.0, 1.0*(-3.0)+2.0*4.0);
  if( !c.equals(expected, 1e-8) )
    std::cerr<<"->bad multiplication result!! expected "<<expected.printCartesian()<<std::endl;
}

inline double square( const double& x ) { return x*x; }
void testDivision() {
  std::cout<<"======================================================="<<std::endl;
  cout << "Testing division\n";
  const Complex a = Complex::fromCartesian(2.0, 1.0);
  const Complex b = Complex::fromCartesian(-3.0, 4.0);
  const Complex c = a.div(b);
  std::cout <<a.printCartesian()<<" / "<<b.printCartesian()<<" = "<<c.printCartesian()<<std::endl;
  const double squareMagnitudeB = square( b.getMagnitude() );
  const Complex expected =
    Complex::fromCartesian( (2.*(-3.0)+1.0*4.0) / squareMagnitudeB,
			    (1.0*(-3.0)-2.0*4.0) / squareMagnitudeB );
  if( !c.equals(expected, 1e-6) ) std::cerr<<"->bad division result!! expected "<<expected.printCartesian()<<std::endl;
}

int main() {
  testCartesian();
  testPolar();
  testAddition();
  testSubtraction();
  testMultiplication();
  testDivision();
  return 0;
}

