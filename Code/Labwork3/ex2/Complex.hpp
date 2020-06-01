#pragma once

#include <string>

class Complex {
  // This class can be implemented using either Cartesian or polar coordinates.
  // We don't want to expose the internal representation too much.
  // In other words, the implementation may change, with a minimum impact on
  // users' usage of it ... so, pure OOP is used.
  double m_inter[2];

  // empty constructor
  Complex();

  // Constructor is private (also, this hides the default constructor)
  Complex(const double, const double);

  // converts the current number to Cartesian representation
  void toCartesian( double&real, double& imag ) const ;

  // converts the current number to polar representation
  void toPolar( double&mag, double& angle ) const ;

  // returns the same complex number in Polar representation
  // from its Cartesian representation
  static void CartesianToPolar( const double real, const double imag,
				double&mag, double &angle );

  // returns the same complex number in Cartesian representation
  // from its Polar representation
  static void PolarToCartesian( const double real, const double imag,
				double&mag, double &angle );

public:

  // FACTORY: creates a new Complex number from its Cartesian representation
  // @param real: the real part of the to create complex number
  // @param imag: the real part of the to create complex number
  // @return the complex number "real+i.imag"
  static Complex fromCartesian( const double real, const double imag ) ;

  // FACTORY: creates a new Complex number from its polar representation
  // @param mag: the magnitude of the complex number to create
  // @param imag: the angle of the complex number to create
  // @return the complex number "mag.exp(i.angle)"
  static Complex fromPolar( const double mag, const double angle ) ;

  // getters
  double getReal() const;
  double getImaginary() const;
  double getMagnitude() const;
  double getAngle() const;

  // setters
  void setReal(const double real);
  void setImaginary(const double imag);
  void setMagnitude(const double mag);
  void setAngle(const double angle);

  // some binary operations (returns a new number)
  Complex add(const Complex&) const;
  Complex sub(const Complex&) const;
  Complex mult(const Complex&) const;
  Complex div(const Complex&) const;

  // check that two complex numbers are equals
  bool equals(const Complex&) const;
  bool equals(const Complex&, const double& epsilon) const;

  // display ... we miss friend function to do it correctly
  // so here "old" solution

  // display in Cartesian form
  std::string printCartesian() const;

  // display in Polar form
  std::string printPolar() const;

};

