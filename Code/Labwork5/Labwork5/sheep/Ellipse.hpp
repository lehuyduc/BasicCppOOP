/*
 *  Ellipse.hpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 05/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */

#pragma once

#include "Graphic.hpp"

class Ellipse : public virtual Graphic
{
  //TODO
    const unsigned m_width;
    const unsigned m_height;

public:
  Ellipse( const unsigned x, const unsigned y, // center of ellipse
	     const unsigned w, const unsigned h,
	     const string c )
    : Graphic(x,y,c), m_width(w), m_height(h)
  {}

  Ellipse( const Ellipse& r )
    : Graphic(r.m_x, r.m_y, r.m_color), m_width(r.m_width), m_height(r.m_height)
  {}


  virtual bool isPrint( const unsigned x, const unsigned y ) const {
      //  return x==m_x && y==m_y;
        Point origin = Point(m_x, m_y);
        double dx = double(abs(x - origin.x)) / (m_width);
        double dy = double(abs(y - origin.y)) / (m_height);
        //if (dx*dx + dy*dy<=1) cout << x << " " << y << " " << m_x << " " << m_y << " " << dx << " " << dy << "\n";
        return dx*dx + dy*dy <= 1;
  }
};
