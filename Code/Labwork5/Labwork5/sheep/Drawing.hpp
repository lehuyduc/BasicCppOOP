/*
 *  Drawing.hpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 04/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */
#pragma once

#include "Graphic.hpp"

class Drawing
{
  struct cell { // cell is the list of shape that will be drawn
    Graphic const & m_g; // the data
    cell * m_next; // the pointer to next item
    cell(Graphic const& g, cell*n) : m_g(g), m_next(n) {}
    ~cell() {
      if (m_next) {
	      delete m_next;
      }
    }
  };
  const string m_back; // background color, if doesn't print then use this color
  const unsigned m_width;
  const unsigned m_height;
  cell* m_graphics;

public:
  Drawing(const string back, const int width, const int height)
    : m_back(back), m_width(width), m_height(height), m_graphics(NULL)
  {}
  ~Drawing() {
    if (m_graphics)
      delete m_graphics;
  }
  void operator+=( Graphic const& g ) {
    m_graphics = new cell( g, m_graphics );
  }
  void draw() const {
    std::cout<<'/';
    for (unsigned x=0; x<m_width; ++x ) std::cout<<'-';
    std::cout<<'\\'<<std::endl;
    for ( unsigned y=m_height; y-- > 0; ) {
      std::cout<<'|';
      for (unsigned x=0; x<m_width; ++x ) {
        string color = m_back;
        for ( cell* c=m_graphics; c; c=c->m_next ) {
          Graphic const& g = c->m_g;

          if (g.isPrint(x, y)) {
            color = g.get_color();
          }
        }
        std::cout << color ;
      }
      std::cout<<'|'<<std::endl;
    }
    std::cout<<'\\';
    for (unsigned x=0; x<m_width; ++x ) std::cout<<'-';
    std::cout<<'/'<<std::endl;
  }
};
