#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
using std::cout;
void testVector() {
  const double array[] = {0.0, 1.0, 2.0, 3.0, 4.0};
  Vector a(5, array), b(5, 1.0);
  Vector c(a+b);
  std::cout<<"a="<<a<<std::endl;
  std::cout<<"b="<<b<<std::endl;
  std::cout<<"c="<<c<<std::endl;
  if( !(a == a) )
    std::cerr<<"operator== does not works"<<std::endl;
  if( c-b != a ) {
    std::cerr<<"operator+ and operator- are not consistent"<<std::endl;
    std::cout<<(c-b)<<std::endl;
  }
  if( 6.0*5.0/2.0 != b * c ) {
    std::cerr<<"operator* does not work"<<std::endl;
    std::cout<<(b*c)<<std::endl;
  }
}


void testMatrix() {
  std::cout<<"Try to build a bad matrix (except an exception)"<<std::endl;
  try {
    Matrix a(0, 1);
  } catch(MatrixException me) {
    std::cout<<"***** Exception raised successful: "<<me.m_msg<<std::endl;
  }
    cout << "---------\n\n-------------------\nTesting add/sub\n";
  Matrix a(3, 4, 1.0);
  std::cout <<"Matrix a("<<a.getHeight()<<","<<a.getWidth()<<","<<a[0][0]<<"):"<<std::endl;
  for(unsigned r=0; r<a.getHeight(); r++ ) {
    for(unsigned c=0; c<a.getWidth(); c++ ) {
      std::cout<<a[r][c]<<" ";
    }
    std::cout<<std::endl;
  }

  Matrix a1(3, 4, -1.0);
  std::cout <<"Matrix a1("<<a1.getHeight()<<","<<a1.getWidth()<<","<<a1[0][0]<<"):"<<std::endl;
  for(unsigned r=0; r<a1.getHeight(); r++ ) {
    for(unsigned c=0; c<a1.getWidth(); c++ ) {
      std::cout<<a1[r][c]<<" ";
    }
    std::cout<<std::endl;
  }
  {
    Matrix sum(a+a1);
    for(unsigned r=0; r<sum.getHeight(); r++ )
      for(unsigned c=0; c<sum.getWidth(); c++ )
	if( sum[r][c] != 0.0 ) {
	  std::cerr<<"Matrix::operator+ does not work"<<std::endl;
      }
  }
  {
    Matrix sub(a-a1);
    for(unsigned r=0; r<sub.getHeight(); r++ )
      for(unsigned c=0; c<sub.getWidth(); c++ )
	if( sub[r][c] != 2.0 ) {
	  std::cerr<<"Matrix::operator- does not work"<<std::endl;
      }
  }

  cout << "---------\n\n-------------------\nTesting mult\n";

  Matrix b(4, 5, 2.0);
  std::cout <<"Matrix b("<<b.getHeight()<<","<<b.getWidth()<<","<<b[0][0]<<"):"<<std::endl;
  for(unsigned r=0; r<b.getHeight(); r++ ) {
    for(unsigned c=0; c<b.getWidth(); c++ ) {
      std::cout<<b[r][c]<<" ";
    }
    std::cout<<std::endl;
  }

  Matrix c(a*b);
  std::cout <<"Matrix c = a*b:"<<std::endl;
  for(unsigned r=0; r<c.getHeight(); r++ ) {
    for(unsigned col=0; col<c.getWidth(); col++ ) {
      std::cout<<c[r][col]<<" ";
    }
    std::cout<<std::endl;
  }

    cout << "---------\n\n-------------------\nTesting matrix mult vector \n";

  Vector v1(b.getWidth(),1.0);
  double val = 0.5;
  for(unsigned row=0; row<b.getHeight(); row++) {
    for(unsigned col=0; col<b.getWidth(); ++col) {
      b[row][col] = val;
      val += 1.0;
    }
  }
  std::cout <<"Matrix b("<<b.getHeight()<<","<<b.getWidth()<<","<<b[0][0]<<"):"<<std::endl;
  for(unsigned r=0; r<b.getHeight(); r++ ) {
    for(unsigned c=0; c<b.getWidth(); c++ ) {
      std::cout<<b[r][c]<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"Vector v1("<<v1.dimension()<<"):"<<std::endl;
  v1.print();
  std::cout<<std::endl;
  std::cout<<"b*v1 = ";
  Vector v2(b*v1);
  v2.print();
  std::cout<<std::endl;
  for(unsigned i=0; i<v2.dimension(); ++i) {
    if( v2[i] != 12.5 + 25.0*i )
      std::cerr<<"Matrix::operator*(const Vector&) does not work!"<<std::endl;
  }
}


int main() {
    // Code to test why we need double operator[](int i) const in addition to double& operator[] (int i) const
   /*
    const Matrix aa(3,4,1.5);
    Matrix ab(3,4,1.5);
  //aa[2][1] = 3;
  ab[2][1] = 2;
  cout << ab[2][1] << "\n";
  const Matrix::ConstMatrixRow row2 = aa[2];
  cout << row2[1] << " AA\n";
  return 0;
    */

  testVector();
  try {
    testMatrix();
  } catch( MatrixException me ) {
    std::cerr<<"MatrixException raised caught in main: "<<me.m_msg<<std::endl;
  }

  return 0;
}
