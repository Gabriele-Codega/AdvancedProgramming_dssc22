#include "matrix.hpp"
#include <iostream>
#include <vector>

int main(){
  Cmatrix<int> A(2,3);
  Cmatrix<int> B(3,4);
  Cmatrix<int> C(2,4);


  A.read_from_file("A.dat");
  B.read_from_file("B.dat");
  C=A*B;
  C.print_to_file("C.dat");
  return 0;
}
