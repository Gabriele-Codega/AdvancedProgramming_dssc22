#ifndef EQUATION_H
#include "coeffs.hpp"
#include "complex.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#define EQUATION_H

template <typename T>
class CQuadratic_Equation{
public:
  CCoeffs<T> coeffs;
  CComplex<double> sols[2];

  //get coefficients
  void get_coefficients(const std::string filename);

  // add function to solve equation with given coeffs
  void solve();

  //print solutions
  void print_solutions(const std::string filename);
};




//=========================
//======= Functions =======

// get coefficients
template <typename T>
void CQuadratic_Equation<T>::get_coefficients(const std::string filename){
  std::ifstream file(filename);
  if(!file){
    coeffs.ask_for_input();
  } else {
    T a;
    T b;
    T c;
    file >> a >> b >> c;
    coeffs.set(a,b,c);
  }
  file.close();
}

// add function to solve equation with given coeffs
template <typename T>
void CQuadratic_Equation<T>::solve(){
  T a,b,c;
  a = coeffs.geta();
  b = coeffs.getb();
  c = coeffs.getc();

  if (a == 0){
    std::cout<<"a shall not be zero."<<std::endl;
    exit(1);
  }

  T delta;
  T inv2a = 1/(2*a);

  delta = b * b - 4*a*c;

  if (delta >= 0){
    T root = std::sqrt(delta);
    sols[0].set_values((-b+root)*inv2a,0);
    sols[1].set_values((-b-root)*inv2a,0);
  } else {
    T root = std::sqrt(-delta);
    sols[0].set_values(-b*inv2a,root*inv2a);
    sols[1].set_values(-b*inv2a,-root*inv2a);
  }
}

//print solutions
template <typename T>
void CQuadratic_Equation<T>::print_solutions(const std::string filename){
  std::ofstream file;
  file.open(filename,std::ios_base::app);
  if(!file){
      std::cout<<"x1 = "<<sols[0];
      //sols[0].print();
      std::cout<<"x2 = "<<sols[1];
      //sols[1].print();
  } else {
    T a,b,c;
    a = coeffs.geta();
    b = coeffs.getb();
    c = coeffs.getc();
    file<<"Coefficients are: "<<"a = "<<a<<"b = "<<b<<"c = "<<c<<std::endl;
    file<<"Solutions are: "<<std::endl;
    file<<"x1 = "<<sols[0];
    file<<"x2 = "<<sols[1];
    file<<"------------------------------"<<std::endl;
  }
  file.close();
}


#endif
