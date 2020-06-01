#include "PointList.hpp"

void PointList::cleanup() {
  while(m_first) {
    Element*e = m_first;
    m_first = m_first->m_next;
    delete (Point*)e->m_data;
    delete e;
  }
}

void PointList::copy(const PointList& l) {
  // same code but using the PointList::add function ...
  // will be solved using polymorphism!
  m_first = NULL;
  for(PointListIterator i = l.getIterator(); !i.ended(); i.next()) {
    add(i.head());
  }    
}

PointList::PointList(const PointList&l) {
  // duplicate the points ...
  copy(l);
}

PointList::~PointList() {
  // cleanup the previous list (delete the points)
  cleanup();
}


PointList& PointList::operator=(const PointList&l) {
  if( this != &l ) {
    cleanup();
    copy(l);
  }
  return *this;
}

