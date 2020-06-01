#include "List.hpp"
#include <iostream>
#include <vector>
using std::cout;

void List::cleanup() {
  while(m_first) {
    Element*e = m_first;
    m_first = m_first->m_next;
    delete e;
  }
}

void List::copy(const List&l) {
    std::vector<const void*> tmp;
  m_first = NULL;
  for(ListIterator i = l.getIterator(); !i.ended(); i.next()) {
    tmp.push_back(i.head());
  }
    for (int i=int(tmp.size())-1; i>=0; i--) add(tmp[i]);
}

List::List() {
    m_first = nullptr;
}

List::List(const List&l) {
  copy(l);
}

List::~List() {
  cleanup();
}



List& List::operator=(const List&l) {
  if( this != &l ) {
    cleanup();
    copy(l);
  }
  return *this;
}
