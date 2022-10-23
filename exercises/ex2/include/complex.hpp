#ifndef COMPLEX_H
#include <iostream>
#define COMPLEX_H
class CComplex{
  double re;
  double im;
public:
  //constructor
  CComplex();
  CComplex(double x, double y);

  // assign values
  void set_values(double x, double y);

  //functions to get real and imaginary parts
  double getre();
  double getim();

  //print the number
  friend std::ostream& operator<<(std::ostream& os, const CComplex& z);
  void print();

  //algebraic operators
  CComplex operator+(const CComplex& b);
  CComplex operator-(const CComplex& b);
  CComplex operator*(const CComplex& b);
  //CComplex operator+(const CComplex& b)


};

#endif
