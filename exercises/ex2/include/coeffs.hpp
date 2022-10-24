#ifndef COEFFS_H
#include <iostream>
#define COEFFS_H

// add class for coefficients
template <typename T>
class CCoeffs{
  T a;
  T b;
  T c;

public:
  //constructor
  CCoeffs();

  //set values
  void set(T a, T b, T c);

  // add function to input coefficients
  void ask_for_input();

  //add function to print coefficients
  void print();

  //get coefficients
  T geta();
  T getb();
  T getc();
};

//=======================================
//============= Functions ===============

//constructor
template <typename T>
CCoeffs<T>::CCoeffs():a(0),b(0),c(0){}
//set values
template <typename T>
void CCoeffs<T>::set(T x, T y, T z){
  a = x;
  b = y;
  c = z;
}

// add function to input coefficients
template <typename T>
void CCoeffs<T>::ask_for_input(){
  T x,y,z;
  std::cout<<"Enter the coefficients"<<std::endl;
  std::cin>>x>>y>>z;
  a = x;
  b = y;
  c = z;
}

//add function to print coefficients
template <typename T>
void CCoeffs<T>::print(){
  std::cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<std::endl;
}

//get coefficients
template <typename T>
T CCoeffs<T>::geta(){
  return a;
}
template <typename T>
T CCoeffs<T>::getb(){
  return b;
}
template <typename T>
T CCoeffs<T>::getc(){
  return c;
}


#endif
