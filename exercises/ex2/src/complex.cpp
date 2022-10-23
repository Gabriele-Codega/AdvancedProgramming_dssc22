#include "complex.hpp"
#include <iostream>

CComplex::CComplex():re(0),im(0){}
CComplex::CComplex(double x, double y):re(x),im(y){}

// assign values
void CComplex::set_values(double x, double y){
  re = x;
  im = y;
}

//functions to get real and imaginary parts
double CComplex::getre(){
  return re;
}
double CComplex::getim(){
  return im;
}

//print the number
std::ostream& operator<<(std::ostream& os, const CComplex& z){
  os<<z.re<<"+("<<z.im<<")i"<<std::endl;
  return os;
}
void CComplex::print(){
  std::cout<<re<<"+("<<im<<")i"<<std::endl;
}

//algebraic operators
CComplex CComplex::operator+(const CComplex& b){
  CComplex result;
  result.re = re + b.re;
  result.im = im + b.im;
  return result;
}

CComplex CComplex::operator-(const CComplex& b){
  CComplex result;
  result.re = re - b.re;
  result.im = im - b.im;
  return result;
}

CComplex CComplex::operator*(const CComplex& b){
  CComplex result;
  result.re = re*b.re - im*b.im;
  result.im = im*b.re + re*b.im;
  return result;
}
