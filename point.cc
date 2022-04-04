#include "point.h"

 Point::Point(Fraction _x, Fraction _y) {
  x = _x;
  y = _y;   
 }
 
 Point::~Point(void) {}   
 
 Point Point::operator+ (Point rhs) {
  Fraction f1,f2;
  f1 = x + rhs.x;
  f2 = y + rhs.y;
  
  return Point(f1,f2); 
 }
 
  Point Point::operator-(Point rhs) {
  Fraction f1,f2;
  f1 = x - rhs.x;
  f2 = y - rhs.y;
  
  return Point(f1,f2); 
 }
 
  Point Point::operator* (Fraction f) {
  Fraction f1,f2;
  f1 = f * x;
  f2 = f * y;
  
  return Point(f1,f2); 
 }
 
  Fraction Point::operator* (Point p) {
  Fraction result;
  result  = x * p.y - y * p.x;
  return result; 
  }
  
  //bool Point:: operator <(Point rhs) {
  //  return (x < rhs.x) or (x == rhs.x && y < rhs.y) ;
  //}
  
  
 std::istream &operator>>(std::istream &is,Point &p) {
   Fraction
    x,y;
   char                          
    comma,openP, closeP;
   is >> openP >> x >> comma >> y >> closeP;
   p = Point(x,y);
   return is;
   
   } 
  
 std::ostream &operator<<(std::ostream &os, Point p) {
    os << "(" << p.getX() << "," << p.getY() << ")" ;
    return os;
  }
