#pragma once
#include <iostream>

class Point {
  int m_x, m_y;
 public:
  void init( int x, int y ) {
    m_x = x;
    m_y = y;
  }
  void move( int dx, int dy ) {
    m_x += dx;
    m_y += dy;
  }
  void print() {
    std::cout << "Point(" << m_x << "," << m_y << ")\n";
  }
};

