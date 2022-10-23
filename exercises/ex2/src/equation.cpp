#include "equation.hpp"
#include "coeffs.hpp"
#include "complex.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

// get coefficients
void CQuadratic_Equation::get_coefficients(const std::string filename){
  std::ifstream file(filename);
  if(!file){
    coeffs.ask_for_input();
  } else {
    double a;
    double b;
    double c;
    file >> a >> b >> c;
    coeffs.set(a,b,c);
  }
  file.close();
}

// add function to solve equation with given coeffs
void CQuadratic_Equation::solve(){
  double a,b,c;
  a = coeffs.geta();
  b = coeffs.getb();
  c = coeffs.getc();

  if (a == 0){
    std::cout<<"a shall not be zero."<<std::endl;
    exit(1);
  }

  double delta;
  double inv2a = 1/(2*a);

  delta = b * b - 4*a*c;

  if (delta >= 0){
    double root = std::sqrt(delta);
    sols[0].set_values((-b+root)*inv2a,0);
    sols[1].set_values((-b-root)*inv2a,0);
  } else {
    double root = std::sqrt(-delta);
    sols[0].set_values(-b*inv2a,root*inv2a);
    sols[1].set_values(-b*inv2a,-root*inv2a);
  }
}

//print solutions
void CQuadratic_Equation::print_solutions(const std::string filename){
  std::ofstream file;
  file.open(filename,std::ios_base::app);
  if(!file){
      std::cout<<"x1 = "<<sols[0];
      //sols[0].print();
      std::cout<<"x2 = "<<sols[1];
      //sols[1].print();
  } else {
    double a,b,c;
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
