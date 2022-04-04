// defines int32_t and related issues
#include <cstdint>
#include <iostream>

// if not defined do from here to endif

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
 // functions are public  
 public:
  Fraction(int32_t _num=0 , int32_t _den =1); // default parameters
  ~Fraction(void);
 
  Fraction operator+(Fraction rhs);
  Fraction operator-(Fraction rhs);
  Fraction operator*(Fraction rhs);
  Fraction operator/(Fraction rhs);
  Fraction operator=(Fraction rhs);

  bool operator==(Fraction rhs);
  bool operator!=(Fraction rhs);
  bool operator<(Fraction rhs);
  bool operator>(Fraction rhs);
  bool operator<=(Fraction rhs);
  bool operator>=(Fraction rhs);

  int32_t getNum() { return num; }
  int32_t getDen() { return den; }


 // typically data are private
 private:
  int32_t
    num,
    den;

};

std::istream &operator>>(std::istream &, Fraction &);
std::ostream &operator<<(std::ostream &, Fraction);


#endif
