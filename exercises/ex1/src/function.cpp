#include "function.hpp"
#include "class.hpp"
#include <iostream>
#include <cmath>


// add function to solve equation with given coeffs
void solve_quadratic_equation(CCoeffs coeffs){
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
    std::cout<<"x1 = "<< (-b+root)*inv2a<<", x2 = "<<(-b-root)*inv2a<<std::endl;
  } else {
    double root = std::sqrt(-delta);
    std::cout<<"x1 = "<< -b*inv2a<<"+i "<<root*inv2a <<", x2 = " <<-b*inv2a<<"-i "<<root*inv2a<<std::endl;
  }
}
