#pragma once

#include <iostream>

struct MatrixException {
  std::string m_msg;
  MatrixException(const char*const msg) : m_msg(msg) {}
  MatrixException(const MatrixException& me) : m_msg(me.m_msg) {}
};

class Vector;

// Matrix in R^{n,m}
// So having n rows, m columns
class Matrix {
  unsigned m_height; // number of rows (1st dimension)
  unsigned m_width; // number of columns (2nd dimension)
  double *m_v; // values

  // data are set per row
  unsigned offset(const unsigned row, const unsigned col) const {
    return m_width*row + col;
  }

  // private utilities
  void cleanup() {
    delete m_v;
  }

  //
  void allocate() {
    if( m_width == 0 || m_height == 0 )
      throw MatrixException("cannot creates Matrix with 0 values");
    m_v = new double[m_width * m_height];
  }

  //
  void copy(const double*const d) {
    for(unsigned r=m_height; r--; )
      for(unsigned c=m_width; c--; )
      {
        const unsigned offset = Matrix::offset(r,c);
        m_v[offset] = d[offset];
      }
  }

  //
  void copy(const Matrix& m) {
    m_width = m.m_width;
    m_height = m.m_height;
    allocate();
    copy(m.m_v);
  }


public:

  // construtor
  Matrix( const unsigned height, const unsigned width, const double& init=0.0 ) :
    m_height(height), m_width(width)
  {
    allocate();
    for(unsigned r=height; r--; )
      for(unsigned c=width; c--; )
	      m_v[offset(r,c)] = init;
  }

  // construtor
  Matrix(const unsigned height, const unsigned width, const double* array ) :
    m_height(height), m_width(width)
  {
    allocate();
    copy(array);
  }

  // construtor
  Matrix(const Matrix& m) { copy(m); }

  // destructor
  ~Matrix() { cleanup(); }


  // returns the number of rows
  unsigned getHeight() const { return m_height; }
  // returns the number of columns (size of a row)
  unsigned getWidth() const { return m_width; }

  // public utility class
  class MatrixRow {
    const unsigned m_width;
    double*m_v;
    MatrixRow();
  public:
    MatrixRow(const unsigned row, Matrix&m) :
        m_width(m.m_width), m_v(m.m_v+(row*m.m_width)) {}

    double&operator[](const int col) {
      if( col<0 || col>=int(m_width) )
	      throw MatrixException( "Matrix: column out-of-bound access" );
      return m_v[col];
    }
  };

  // access to element operator
  MatrixRow operator[](const int row) {
    if( row<0 || row>=int(m_height) )
      throw MatrixException( "Matrix: row out-of-bound access" );
    return MatrixRow(row,*this);
  }

  // This method is implemented into the .cpp file already.
  Matrix operator+(const Matrix&m) const;

  /* Student work start here ! */

  Matrix& operator=(const Matrix& m );


  // utility
    class ConstMatrixRow {
    // TODO
        const int m_width;
        double *m_v;
        ConstMatrixRow();

    public:
        ConstMatrixRow(int row, const Matrix&m) :
            m_width(m.m_width), m_v(m.m_v+(row*m.m_width)) {}

        double operator[](const int col) const {
            //std::cout << "print const\n";
            if (col<0 || col>=m_width)
                throw MatrixException( "Matrix const: column out-of-bound access" );
            return m_v[col];
        }
    };

  // const acces to element operator
  ConstMatrixRow operator[](const int row) const {
    // TODO
        if (row<0 || row>=m_height) {
            throw MatrixException( "Matrix const: row out-of-bound access" );
        }
        return ConstMatrixRow(row, *this);
  }

  // These three methods have to be implemented into the .cpp file.
  Matrix operator-(const Matrix&m) const;

  Matrix operator*(const Matrix&m) const;

  Vector operator*(const Vector&) const;
};
