#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>
using std::cout;
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

Matrix& Matrix::operator=(const Matrix& m ) {
    // TODO
    // TODO
    if (this!=&m) {
        cleanup();
        copy(m);
    }
    return *this;
  }

Matrix Matrix::operator-(const Matrix&m) const{
  // TODO
  if (m_width!=m.m_width || m_height!=m.m_height)
    throw MatrixException("Matrix::operator- bad matrix dimensions");

  Matrix res(m_height,m_width, 0.0);
  for (int i=0;i<m_height;i++)
    for (int j=0;j<m_width;j++)
        res[i][j] = (*this)[i][j] - m[i][j];
  return res;
}

Matrix Matrix::operator*(const Matrix&m) const{
    // correct only if number of columns (width) of first matrix
    // equals the number of lines (height) of second matrix
    if (m_width!=m.m_height)
        throw MatrixException("Matrix::operator* dimensions of two matrices bad, can't multiply");
    // TODO
    Matrix res = Matrix(m_height,m.m_width, 0.0);
    for (int i=0;i<m_height;i++)
        for (int j=0;j<m.m_width;j++) {
            res[i][j] = 0;
            for (int k=0;k<m_width;k++) res[i][j] += (*this)[i][k] * m[k][j];
        }
    return res;
}

Vector Matrix::operator*(const Vector&v) const {
    // TODO
    if (m_width!=v.m_n)
        throw MatrixException("Matrix::operator*Vector dimension of matrix and vector doesn't compatible");
    Vector res(m_height,0.0);
    for (int i=0;i<m_height;i++) {
        for (int j=0;j<m_width;j++) res[i] += (*this)[i][j] * v[j];
    }
    return res;
}


