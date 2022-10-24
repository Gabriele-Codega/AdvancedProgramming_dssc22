#include "coeffs.hpp"
#include "complex.hpp"
#include <iostream>

int main(){
  CComplex<float> x(1,3);
  CComplex<float> y(2,4);

  (x+y).print();
  return 0;
}
