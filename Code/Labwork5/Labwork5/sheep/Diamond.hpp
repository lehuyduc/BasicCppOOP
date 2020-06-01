/*
 *  Diamond.hpp
 *  Labwork5
 *
 *  Created by Lilian Aveneau on 05/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */

#pragma once

#include "Graphic.hpp"
#include "Point.hpp"
using std::cout;
using std::min;

class Diamond : public virtual Graphic
{
  // TODO
    const unsigned m_width; // width and height of half the diamond
    const unsigned m_height;

public:
    Diamond( const unsigned x, const unsigned y, // bottom left
        const unsigned w, const unsigned h,
        const string c )
        : Graphic(x,y,c), m_width(w), m_height(h)
    {}

    Diamond( const Diamond& r )
    : Graphic(r.m_x, r.m_y, r.m_color), m_width(r.m_width), m_height(r.m_height)
    {}

    static int dd;
    bool isPrint( const unsigned x, const unsigned y ) const {
        Point center = Point(m_x + m_width, m_y + m_height);
        int distance_from_center = abs(center.x - x) + abs(center.y - y);
        return distance_from_center <= int(min(m_width,m_height));
    }

};
