#pragma once

#include <iostream>
#include <cstdio>

class Point {
  static int m_allocated;

  int m_x, m_y;
public :
  Point( int x=0, int y=0 ) : m_x(x), m_y(y)
  {}

  ~Point() {}

  void print() const {
    std::cout<<"Point("<<m_x<<","<<m_y<<")"<<std::endl;
  }

  void* operator new(size_t sz) {
    ++m_allocated;
    void*ptr = ::new char[sz];
    //printf("allocate point at %p\n",ptr);
    return ptr;
  }
  void operator delete(void*ptr) {
    --m_allocated;
    //printf("de-allocate point at %p\n",ptr);
    ::delete (char*)ptr;
  }

  static int nbAllocated() { return m_allocated; }

  int getm_x() const {return m_x;}
  int getm_y() const {return m_y;}
};
