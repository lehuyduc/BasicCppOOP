#pragma once

#include <cmath>
// This file concerns the internal representation of complex number.
// If we change it, only this file should be impacted ...

// internal representation is Cartesian ...
#define M_MAG m_inter[0]
#define M_ANGLE m_inter[1]

Complex::Complex() {
    M_MAG = 0;
    M_ANGLE = 0;
}

Complex::Complex(const double mag, const double angle) {
   // M_MAG = sqrt(real*real + imag*imag);
  //  M_ANGLE = atan2(imag,real);
    M_MAG = mag;
    M_ANGLE = angle;
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

Complex Complex::fromPolar(const double mag, const double angle) {
    return Complex(mag, angle);
}

Complex Complex::fromCartesian( const double real, const double imag ) {
    double mag, angle;
    CartesianToPolar(real, imag, mag, angle);
    return Complex(mag, angle);
}


void Complex::toCartesian( double&real, double& imag ) const {
    PolarToCartesian(M_MAG, M_ANGLE, real, imag);
}

void Complex::toPolar( double&mag, double& angle ) const {
    mag = M_MAG;
    angle = M_ANGLE;
}




