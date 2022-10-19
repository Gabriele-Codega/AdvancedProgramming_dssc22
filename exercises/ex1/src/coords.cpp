#include "class.hpp"
#include <iostream>

//constructor
CCoeffs::CCoeffs():a(0),b(0),c(0){}

// add function to input coefficients
void CCoeffs::ask_for_input(){
  double x,y,z;
  std::cout<<"Enter the coefficients"<<std::endl;
  std::cin>>x>>y>>z;
  a = x;
  b = y;
  c = z;
}

//add function to print coefficients
void CCoeffs::print(){
  std::cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<std::endl;
}

//get coefficients
double CCoeffs::geta(){
  return a;
}
double CCoeffs::getb(){
  return b;
}
double CCoeffs::getc(){
  return c;
}
