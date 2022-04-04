//#include <cstdint>
#include <iostream>
#include "fraction.h"

#ifndef _POINT_H
#define _POINT_H

class Point {
   
  public:
   Point(Fraction _x = 0/1, Fraction  _y = 0/1);
   ~Point(void);
   
   Point operator+(Point rhs);
   Point operator-(Point rhs);
   Point operator*(Fraction);
   Fraction operator*(Point);

   Fraction getX() { return x; }
   Fraction getY() { return y; }
   
   private:
   Fraction
     x,
     y;
   
  };
  
  std::istream &operator>>(std::istream &, Point &);
  std::ostream &operator<<(std::ostream &, Point);
  
 #endif
