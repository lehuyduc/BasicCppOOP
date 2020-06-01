#pragma once

#include <cstdlib>
#include <iostream>
#include "Point.hpp"
using std::cout;

class List {
private:
  // private methods
  void cleanup();
  void copy(const List&);

protected:
struct Element {
    const void*m_data;
    Element* m_next;
    // TODO
    Element(const void* content, Element* next_ele) : m_data(content), m_next(next_ele) {}
  };
  Element* m_first;

public:
  class ListIterator {
    // TODO
    Element* i_first;
    Element* cur_pos;

    void cleanup() {
        // THE LINE BELOW IS AN ERROR. ITERATORS
        //delete i_first; delete cur_pos;
    }

    void copy(const ListIterator& it) {
        cleanup();
        i_first = it.i_first;
        cur_pos = it.cur_pos;
    }

  public:
    // TODO: iterator constructors, destructor

    ListIterator(const ListIterator& it) : i_first(it.i_first), cur_pos(it.cur_pos) {}

    ListIterator(const List& l) {i_first = l.m_first; cur_pos = l.m_first;} // NEVER EVER WRITE: m_first = cur_pos = l.m_first; IT CAN GIVE RANDOM RESULTS

    ~ListIterator() {/* DO NOT DELETE DATA IN ITERATOR. ITERATOR IS NOT THE OWNER OF DATA*/}

    const void*head() const // returns the current head of list
    {
        if (cur_pos!=nullptr) return cur_pos->m_data;
        else {cout << "Which idiot called ListIterator.head() on nullptr?\n"; return nullptr;}                                                                     // TODO
    }
    void next()             // jump to the next element
    {
        if (cur_pos!=nullptr) cur_pos = cur_pos->m_next;
        else {cout << "Who called ListIterator.next() on nullptr?\n";}                                                        // TODO
    }
    bool ended() const      // true if current scan is ended
    {
      // TODO
      return (cur_pos==nullptr);
    }

    ListIterator& operator = (const ListIterator& it) {
        if (this!=&it) {
            cleanup();
            copy(it);
        }
        return *this;
    }
  };

  // TODO: constructorS, destructor

  List();
  List(const List& i);
  ~List();

  void add( const void*ptr ) {
    // TODO
        Element* new_head = new Element(ptr, m_first);
        m_first = new_head;
        Point p = *(Point*)ptr;
   //     cout << "adding new head = " << new_head << " " << "point= " << p.getm_x() << " " << p.getm_y() <<  "\n";
  }

  ListIterator getIterator() const {
    // TODO
        return ListIterator(*this);
  }

  List& operator=(const List&l);

  void printer() const {
    Element* cur = m_first;
    while (cur!=nullptr) {
     //   cout << (*(double*)cur->m_data) << " printering\n";
        cur = cur->m_next;
    }
  }

  void printerIterator() const {
    ListIterator it(*this);

    while (!it.ended()) {
       // cout << (*(double*)it.head()) << " printerIterator\n";
        it.next();
    }
  }
};




