#include <iostream>
#include "List.hpp"
using std::cout;

void printListDouble(const List& l);

void printDerivativeListDouble( const List& l ) {
  List::ListIterator i2 = l.getIterator();

  i2.next();
  int counter = 0;
  for( List::ListIterator i1 = l.getIterator(); !i2.ended(); i1.next(), i2.next() ){
    const double a = *(const double*)i2.head();
    const double b = *(const double*)i1.head();
    //cout << i1.head() << " " << i2.head() << " AA\n";
    std::cout << (a-b) << " " << ++counter << "\n";
  }
  std::cout<<std::endl;
}


void printListDouble( const List& l ) {
  List::ListIterator iter = l.getIterator();
  for(int i=0; !iter.ended(); ++i) {
    const double*const pd = (const double*)iter.head();
    std::cout << *pd << " " << " A\n";
    if( (i&0xF) == 0xF )
      std::cout << std::endl;
    iter.next();
  }
}

List createListDouble( double*const d, const unsigned n_number ) {
  List list;
  for(unsigned i=0; i<n_number; ++i) {
    list.add(&d[i]);
  }
  cout << "\n";
  return list;
}

int main() {
  double array[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15
  };

  const List list = createListDouble( array, sizeof(array)/sizeof(double) );

  printListDouble( list );

  cout << "\n--------------------------\nTesting assignment operator\n\n";
  const List l2 = list;
  printListDouble(l2);

  cout << "\n--------------------------\nTesting constructor List(const List& l) operator\n\n";
  printListDouble( List(l2) );

  cout << "\n--------------------------\nTesting before something\n\n";
  printListDouble( list );

  cout << "\n--------------------------\nTesting something\n\n";
  printDerivativeListDouble( list );

  return 0;
}
