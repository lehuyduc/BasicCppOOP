/*
 *  Circle.hpp
 *  Labwork 5
 *
 *  Created by Lilian Aveneau on 04/11/11.
 *  Copyright 2011 XLIM/SIC/IG. All rights reserved.
 *
 */

#pragma once

#include <cmath>
#include "Graphic.hpp"
#include "Point.hpp"

class Circle : public virtual Graphic
{
  // TODO
    const unsigned m_radius;

public:
    Circle( const unsigned x, const unsigned y, // center of circle
        const unsigned r,
        const string c )
        : Graphic(x,y,c), m_radius(r)
    {}

    Circle( const Circle& r )
    : Graphic(r.m_x, r.m_y, r.m_color), m_radius(r.m_radius)
    {}


    virtual bool isPrint( const unsigned x, const unsigned y ) const {
        double dx = double(abs(x - m_x)) / m_radius;
        double dy = double(abs(y - m_y)) / m_radius;
        return dx*dx + dy*dy <= 1;
    }
};
