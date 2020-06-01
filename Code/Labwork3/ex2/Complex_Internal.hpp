#pragma once

// This file concerns the internal representation of complex number.
// If we change it, only this file should be impacted ...

// internal representation is Cartesian ...
#define M_REAL m_inter[0]
#define M_IMAG m_inter[1]

Complex::Complex() {
    M_REAL = 0;
    M_IMAG = 0;
}

Complex::Complex(const double real, const double imag) {
  M_REAL = real;
  M_IMAG = imag;
}

void Complex::CartesianToPolar( const double real, const double imag,
				double& mag, double &angle ) {
  mag = sqrt( real*real + imag*imag );
  angle = atan2(imag,real);
}


void Complex::PolarToCartesian( const double mag, const double angle,
				double& real, double& imag ) {
  real = mag*cos(angle);
  imag = mag*sin(angle);
}


Complex Complex::fromCartesian( const double real, const double imag ) {
  return Complex(real, imag) ;
}

Complex Complex::fromPolar( const double mag, const double angle ) {
  // we reuse the code already written (to minimize the risk of bugs)
  double real, imag;
  PolarToCartesian( mag, angle, real, imag );
  return Complex( real, imag );
}



void Complex::toCartesian( double&real, double& imag ) const {
  real = M_REAL;
  imag = M_IMAG;
}

void Complex::toPolar( double&mag, double& angle ) const {
  CartesianToPolar(M_REAL, M_IMAG, mag, angle);
}




