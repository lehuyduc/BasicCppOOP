#include <cmath>
#include <sstream>
#include "Complex.hpp"
#include <iostream>
using std::cout;
// defines and hides the inner representation of Complex number
#include "Complex_Internal_polar.hpp"

// From now, we do not assume that we use Cartesian or Polar representation ...


double Complex::getReal() const {
  double real, _;
  toCartesian(real, _);
  return real;
}


double Complex::getImaginary() const {
  // TODO
  double _, imag;
  toCartesian(_, imag);
  return imag;
}

double Complex::getMagnitude() const {
    // TODO
    double mag, angle;
    toPolar(mag, angle);
    return mag;
}

double Complex::getAngle() const {
    // TODO
    double mag, angle;
    toPolar(mag, angle);
    return angle;
}

void Complex::setReal(const double real) {
  double _, imag;
  toCartesian(_, imag);
  *this = fromCartesian(real, imag);
}

void Complex::setImaginary(const double imag) {
  // TODO
  double real, _;
  toCartesian(real, _);
  *this = fromCartesian(real, imag);
}

void Complex::setMagnitude(const double mag) {
    // TODO
    double curmag, curangle;
    toPolar(curmag,curangle);
    *this = fromPolar(mag,curangle);
}

void Complex::setAngle(const double angle) {
  // TODO
  double curmag, curangle;
  toPolar(curmag,curangle);
  *this = fromPolar(curmag,angle);
}

Complex Complex::add(const Complex& c) const {
  // TODO
    double x1,y1, x2,y2;
    toCartesian(x1,y1);
    c.toCartesian(x2,y2);
    return fromCartesian(x1+x2,y1+y2);
}

Complex Complex::sub(const Complex& c) const {
    double x1,y1, x2,y2;
    toCartesian(x1,y1);
    c.toCartesian(x2,y2);
    return fromCartesian(x1-x2,y1-y2);
}

Complex Complex::mult(const Complex& c) const {
    double x1,y1, x2,y2;
    toCartesian(x1,y1);
    c.toCartesian(x2,y2);
    return fromCartesian(x1*x2 - y1*y2, x1*y2 + y1*x2);
}

Complex Complex::div(const Complex& c) const {
    double x1,y1, x2,y2;
    toCartesian(x1,y1);
    c.toCartesian(x2,y2);
    double normie = x2*x2 + y2*y2;
    return fromCartesian((x1*x2 + y1*y2) / normie, (-x1*y2 + y1*x2) / normie);
}

bool Complex::equals(const Complex&c) const {
  // check this using Cartesian representation (where unicity exists)
  // indeed 0exp(itheta) == 0exp(ibeta) ... even if theta != beta
  double tr, ti, cr, ci;
  toCartesian(tr, ti);
  c.toCartesian(cr, ci);
  return tr == cr && ti == ci;
}

bool Complex::equals(const Complex&c, const double& epsilon) const {
  // TODO
    double x1,y1, x2,y2;
    toCartesian(x1,y1);
    c.toCartesian(x2,y2);
    return abs(x1-x2)<=epsilon && abs(y1-y2)<=epsilon;
}

std::string Complex::printCartesian() const {
  double real, imag;
  toCartesian(real, imag);
  std::ostringstream string; // or with C++11, use std::to_string(real) ...
  string << real;
  string << ( imag<0.0 ? "-i" : "+i");
  string << fabs(imag);
  return string.str();
}


std::string Complex::printPolar() const {
  double mag, angle;
  toPolar(mag, angle);
  std::ostringstream string; // or with C++11, use std::to_string(real) ...
  string << mag << "exp(" << (angle<0.0?"-i":"i") << fabs(angle)<<")";
  return string.str();
}
