#pragma once

#include "Point.hpp"
#include "List.hpp"

class PointList : protected List { // <- PROTECTED, so you list must allow protected access ...
  void cleanup();
  void copy(const PointList&);

public:
  class PointListIterator : public ListIterator {
  public:
    PointListIterator(const PointListIterator&i) : ListIterator(i) {}
    PointListIterator(const PointList&l) : ListIterator(l) {}
    ~PointListIterator() {}

    const Point& head() const // returns the current head of list
    {
      // TODO
      const Point* p = (const Point*)ListIterator::head();
      return *p;
    }
  };

  PointList() : List() {}

  PointList(const PointList&l);

  ~PointList();

  PointList&operator=(const PointList&l);

  // overloading ...
  void add( const Point& p ) {
    // TODO
    Point *new_point = new Point;
    (*new_point) = p;
    List::add(new_point);
  }

  PointListIterator getIterator() const {
    return PointListIterator(*this);
  }

  void printer() const {
    Element* cur = m_first;
  //  cout << "m_first = " << m_first << "\n";
    while (cur!=nullptr) {
        Point p = *(Point *)cur->m_data;
        cout << "point == " << p.getm_x() << " " << p.getm_y() << " , cur = " << cur << "\n";
        cur = cur->m_next;
    }
  }
};
