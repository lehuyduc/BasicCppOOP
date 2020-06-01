#include <iostream>

/* TODO: define the four arguments a, b, f and c */
void fct(float f, int a=0,int b=1, int c=2) {
  std::cout<<a<<"; "<<b<<"; "<<f<<"; "<<c<<std::endl;
}

int main() {
  fct( 5,6,7,8 ); /* call with four values */
  fct( 5,6,7 ); /* three values */
  fct( 5,6 ); /* 2 values */
  fct( 5 ); /* only one value (f !) */
  return 0;
}
