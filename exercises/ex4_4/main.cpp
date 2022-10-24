#include "matrix.hpp"
#include <iostream>
#include <vector>

int main(){
  unsigned int N{2};
  unsigned int M{2};
  Cmatrix<int> A(N,M);
  Cmatrix<int> B(N,M);
  Cmatrix<int> C(N,M);


  A.read_from_file("A.dat");
  B.read_from_file("B.dat");
  C=A*B;
  C.print_to_file("C.dat");
  return 0;
}
