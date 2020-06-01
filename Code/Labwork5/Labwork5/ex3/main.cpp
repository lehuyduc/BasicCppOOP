#include <iostream>
#include "PointList.hpp"
#include <random>
using std::cout;

int Point::m_allocated = 0u;

int printPointListIterator( PointList::PointListIterator& pli ) {
  if( !pli.ended() ) {
    const Point pt = pli.head();
    pli.next();
    const int pos = printPointListIterator( pli );
    std::cout<<pos<<" ";
    pt.print();
    return pos+1;
  }
  return 0;
}

void printPointList( const PointList& l ) {
  PointList::PointListIterator iter = l.getIterator();
  printPointListIterator( iter );
}

PointList createPointList( const unsigned size ) {
  PointList list;
  int x = 0;
  int y = 0;
  for(unsigned i=0; i<size; ++i) {
    // Cantor numbers
    // 0->0 0
    // 1->1 0
    // 2->0 1
    // 3->2 0
    // 4->1 1
    // 5->0 2
    // 6->3 0
    // etc.
   // cout << "Adding point (" << x << ", " << y << ")\n";
    list.add(Point(x,y));

    if( 0 > --x ) {
      x = y+1;
      y = 0;
    }
    else
      ++y;
  }
  //cout << "Going to print the list in createPointList\n";
  list.printer();
  return list;
}

void test() {
  const PointList list = createPointList( 15 );
  cout << "\n\nprinting list using list.printer()\n";
  list.printer();

  cout << "\n\nprinting list like normal\n";
  printPointList( list );

  cout << "\n\nprinting List testing assignment without reversing order of adding\n";
  const PointList l2 = list;
  printPointList( l2 );

  cout << "\n\nprinting List testing constructor\n";
  printPointList( PointList(l2) );
}

int main() {
  test();
  std::cout<<"allocated points: "<<Point::nbAllocated()<<std::endl;

  return 0;
}
