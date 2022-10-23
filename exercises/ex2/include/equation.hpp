#ifndef EQUATION_H
#include "coeffs.hpp"
#include "complex.hpp"
#include <fstream>
#define EQUATION_H

class CQuadratic_Equation{
public:
  CCoeffs coeffs;
  CComplex sols[2];

  //get coefficients
  void get_coefficients(const std::string filename);

  // add function to solve equation with given coeffs
  void solve();

  //print solutions
  void print_solutions(const std::string filename);
};

#endif
