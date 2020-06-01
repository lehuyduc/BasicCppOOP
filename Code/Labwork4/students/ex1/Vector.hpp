#pragma once
#include <iostream>
#include "Matrix.hpp"

struct VectorException {
  std::string m_msg;
  VectorException( const char*const msg ) : m_msg(msg) {}
  VectorException( const VectorException& ve ) : m_msg(ve.m_msg) {}
};

class Vector 
{
  unsigned m_n; // dimension of the vector space 
  double *m_v;  // coordinates of this instance
  
  Vector();     // hidden to users!

  // private utilities ...
  void cleanup() { 
    delete m_v; 
  }
  
  void copy(const Vector&v) 
  {
    m_n = v.m_n;
    m_v = new double[v.m_n];
    for(unsigned i=m_n; i--; ) m_v[i] = v.m_v[i];
  } 

public:

  // constructor
  Vector(const unsigned n, const double&init=0.0) : 
    m_n(n), m_v(new double[n]) 
  {
    for(unsigned i=n; i--; ) m_v[i] = init;
  } 
  
  // constructor
  Vector(const unsigned n, const double*const v) :
    m_n(n), m_v(new double[n]) 
  {
    for(unsigned i=n; i--; ) m_v[i] = v[i];
  }

  // construtor
  Vector(const Vector& v) { 
    copy(v); 
  }

  // destructor
  ~Vector() { cleanup(); }

  // assignment operator
  Vector& operator=(const Vector&v) {
    if( this != &v ) {
      cleanup(); // free old data in heap
      copy(v);   // allocate and copy
    }
    return *this;
  }
    
  // test if "*this==v"
  bool operator==(const Vector&v) const {
    if( m_n != v.m_n ) return false;
    for(unsigned i=m_n; i--; ) 
      if( m_v[i] != v.m_v[i] ) return false;
    return true;
  }
  
  // size of the vector space
  unsigned dimension() const { return m_n; }


  // addition: returns a new vector containing "*this+v"
  Vector operator+(const Vector&v) const {
    if( m_n != v.m_n ) 
      throw VectorException( "Vector::operator+ applied on vectors"
			     "having different sizes" );
    Vector res(v);
    for(unsigned i=m_n; i--; ) 
      res.m_v[i] += m_v[i];
    return res;
  }

  // print the vector per row ... 
  void print(const unsigned nbPerLine=16) const {
    for(unsigned n=0,i=0; i<m_n; ++n, ++i) {
      if( n==nbPerLine ) std::cout<<std::endl;
      std::cout<<m_v[i]<<" ";
    }
  }

  // defined in Vector.cpp
  friend std::ostream& operator<<(std::ostream&, const Vector&);

  // defined in Matrix.hpp
  friend Vector Matrix::operator*(const Vector&) const;



  /* Student work start here !!! */
  
  // tests if "*this!=v"
  bool operator!=(const Vector&v) const {
    // TODO
  }
  
  // subtraction: returns a new vector containing "*this-v"
  Vector operator-(const Vector&v) const {
    // TODO
  }

  // scalar product
  double operator*(const Vector&v) const {
    // TODO
  }

  friend Vector operator*(const double& d, const Vector&v);
  Vector operator*(const double&d) const {
    // TODO
  }
  
  // acces to an element ... 
  double& operator[](const int i) {
    // TODO
  }

  // idem, but for const vectors!
  double operator[](const int i) const {
    // TODO
  }
    
};


