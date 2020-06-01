#include "Matrix.hpp"
#include "Vector.hpp"

Matrix Matrix::operator+(const Matrix&m) const{
  if(m_width != m.m_width || m_height != m.m_height) 
    throw MatrixException("Matrix::operator+ bad matrix dimensions");
  Matrix res(m_height, m_width, 0.0);
  for(unsigned row=m_height; row--; )
    for(unsigned col=m_width; col--; ) {
      res[row][col] = (*this)[row][col] + m[row][col];
    }
  return res;
}

Matrix Matrix::operator-(const Matrix&m) const{
  // TODO
}

Matrix Matrix::operator*(const Matrix&m) const{
  // correct only if number of rows (width) of first matrix
  // equals the number of lines (height) of second matrix
  
  // TODO
}

Vector Matrix::operator*(const Vector&v) const {
  // TODO
}


