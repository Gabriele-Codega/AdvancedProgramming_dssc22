#include "matrix.hpp"

int main(){
  CMatrix<int> A(2,3);
  CMatrix<int> B(3,4);
  CMatrix<int> C(2,4);


  A.read_from_file("A.dat");
  B.read_from_file("B.dat");
  C=A*B;
  C.write_to_file("C.dat");
  return 0;
}
