#include "equation.hpp"
#include "complex.hpp"
#include "coeffs.hpp"
#include <fstream>


int main(){
  CQuadratic_Equation<double> eq;
  std::string inputfile("coords.txt");
  std::string outfile("solution_history.txt");
  eq.get_coefficients(inputfile);
  eq.coeffs.print();
  eq.solve();
  eq.print_solutions(outfile);

  return 0;
}
