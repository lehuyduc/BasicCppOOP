#include <iostream>
#include <string>

void fct( int i ) {
  std::cout<< "fct( (int) "<<i<<" );"<<std::endl;
}

// TODO: add 3 others functions (unsigned long, float, double)

void fct( unsigned long i ) {
  std::cout<< "fct( (unsigned long) "<<i<<" );"<<std::endl;
}

void fct( float i ) {
  std::cout<< "fct( (float) "<<i<<" );"<<std::endl;
}

void fct( double i ) {
  std::cout<< "fct( (double) "<<i<<" );"<<std::endl;
}

// string/pointer can't use 4 previous definition
void fct(std::string s) {
    std::cout << "fct( (string) "<< s <<" );"<<std::endl;
}

// void pointer is compatible with all pointer type
void fct(double *p) {
    std::cout << "fct( (pointer_double) "<< p <<" );"<<std::endl;
}

void fct(void *p) {
    std::cout << "fct( (pointer) "<< p <<" );"<<std::endl;
}



// TODO: fix the errors ;-)
int main() {
  fct( 'x' );
  fct( 42ul );
  fct( -42 );
  fct( 3.14159f );
  fct( 2.0 );
  fct( "hello" );
  double d;
  fct( &d );
  return 0;
}
