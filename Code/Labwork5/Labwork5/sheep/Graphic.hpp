/*
 *  Graphic.hpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 04/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */
#pragma once

using std::string;

class Graphic
{
protected:
  const unsigned m_x; // we use Oxy coordinate, bottom left is 0 0
  const unsigned m_y;
  const string m_color;

public:

  Graphic(const unsigned x, const unsigned y, const string c)
    : m_x(x), m_y(y), m_color(c)
  {}

  Graphic(const Graphic& g)
    : m_x(g.m_x), m_y(g.m_y), m_color(g.m_color)
  {}

  const string get_color() const {
    return m_color;
  }

  // In fact, we cannot do it correctly: polymorphism is mandatory! -> virtual
  virtual bool isPrint( unsigned x, unsigned y ) const {
    return x == m_x && y == m_y; // actually, draw a Point!
  }
};

