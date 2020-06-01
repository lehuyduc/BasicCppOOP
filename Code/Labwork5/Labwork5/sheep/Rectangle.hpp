/*
 *  Rectangle.hpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 04/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */

#pragma once

#include "Graphic.hpp"

class Rectangle : public virtual Graphic 
{
  const unsigned m_width;
  const unsigned m_height;

public:
  Rectangle( const unsigned x, const unsigned y, 
	     const unsigned w, const unsigned h, 
	     const string c ) 
    : Graphic(x,y,c), m_width(w), m_height(h) 
  {}

  Rectangle( const Rectangle& r ) 
    : Graphic(r.m_x, r.m_y, r.m_color), m_width(r.m_width), m_height(r.m_height) 
  {}

  
  virtual bool isPrint( const unsigned x, const unsigned y ) const {
    return x>=m_x && x<m_x+m_width && y>=m_y && y<m_y+m_height;
  }

};

