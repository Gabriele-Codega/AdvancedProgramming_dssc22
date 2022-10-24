#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <fstream>

template <typename T>
class Cmatrix{
  std::vector<T> elems;
  unsigned int N; //number of rows
  unsigned int M; //number of columns

public:
  Cmatrix(unsigned int N, unsigned int M);

  //assignment operator
  void operator=(const Cmatrix<T> B);


  //read and print from/to file
  void read_from_file(std::string fname);
  void print_to_file(std::string fname);

  //non-optimized multiplication
  Cmatrix<T> operator*(const Cmatrix<T>& B);

};


//====================
//==== Functions =====

template <typename T>
Cmatrix<T>::Cmatrix(unsigned int n, unsigned int m){
  N = n;
  M = m;
  elems.resize(N*M,0); //allocate memory and initialise matrix to zero
}


//assignment
template <typename T>
void Cmatrix<T>::operator=(const Cmatrix<T> B){
  for(int i=0;i<N;i++){
    int row = i*N;
    for(int j=0;j<M;j++){
      elems[row+j] = B.elems[row+j];
    }
  }
}


//read matrix from file
template <typename T>
void Cmatrix<T>::read_from_file(std::string fname){
  std::ifstream infile(fname);
  if(!infile){
    std::cout<<"Couldn't find file "<<fname<<std::endl;
  } else {
    for(int i = 0; i<N;i++){
      int row = i*N;
      for(int j = 0; j<M;j++){
        infile >> elems[row+j];
      }
    }
  }
  infile.close();
}


//write matrix to file
template <typename T>
void Cmatrix<T>::print_to_file(std::string fname){
  std::ofstream outfile(fname);
  if(!outfile){
    std::cout<<"Oops, couldn't open file"<<fname<<std::endl;
  } else {
    for(int i = 0; i<N;i++){
      int row = i*N;
      for(int j = 0; j<M;j++){
        outfile << elems[row+j]<<" ";
        if(j==M-1){
          outfile<<std::endl;
        }
      }
    }
  }
  outfile.close();
}


//non-optimized multiplication
template <typename T>
Cmatrix<T> Cmatrix<T>::operator*(const Cmatrix<T>& B){
  Cmatrix<T> C(N,B.M);
  for(int i=0;i<N;i++){
    int row = i* C.N;
    for(int j=0;j<M;j++){
      for(int k=0;k<B.N;k++){
        C.elems[row+j] += elems[row+k] * B.elems[k*B.N+j];
      }
    }
  }
  return C;
}



#endif
