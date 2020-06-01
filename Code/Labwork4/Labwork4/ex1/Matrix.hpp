#pragma once

class Vector;

class Matrix {
public:
  Vector operator*(const Vector&) const;
};
