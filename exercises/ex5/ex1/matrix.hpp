#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <fstream>

template <typename T>
class Cmatrix{
  T* elems;
  int NROWS; //number of rows
  int NCOLS; //number of columns

public:
  Cmatrix(unsigned int N, unsigned int M);
  ~Cmatrix();

  //assignment operator
  Cmatrix<T>& operator=(const Cmatrix<T>& B);


  //read and print from/to file
  void read_from_file(std::string fname);
  void print_to_file(std::string fname);

  //non-optimized multiplication
  Cmatrix<T> operator*(const Cmatrix<T>& B);

};


//====================
//==== Functions =====

///CHECK INDICES !!

//constructor
template <typename T>
Cmatrix<T>::Cmatrix(unsigned int n, unsigned int m){
  NROWS = n;
  NCOLS = m;
  elems =new T[NROWS*NCOLS]; //allocate memory and initialise matrix to zero
  int size = NROWS*NCOLS;
  for(int i=0;i<size;i++){
    elems[i]=0;
  }
  std::cout<<"Constructor called"<<std::endl;
}

//descrtuctor
template <typename T>
Cmatrix<T>::~Cmatrix(){
  delete[] elems;
  elems = nullptr;
  std::cout<<"Destructor called"<<std::endl;
}


//assignment
template <typename T>
Cmatrix<T>& Cmatrix<T>::operator=(const Cmatrix<T>& B){
  if(this != &B){
    NROWS = B.NROWS;
    NCOLS = B.NCOLS;
    int size = NROWS*NCOLS;

    if (elems != nullptr){
      delete[] elems;
      elems = nullptr;
    }

    if (B.elems == nullptr) {
      elems = nullptr;
    } else {
      elems = new T[size];
      for(int i=0;i<size;i++){
        elems[i] = B.elems[i];
      }
    }
  }
  return *this;
}


//read matrix from file
template <typename T>
void Cmatrix<T>::read_from_file(std::string fname){
  std::ifstream infile(fname);
  if(!infile){
    std::cout<<"Couldn't find file "<<fname<<std::endl;
  } else {
    for(int i = 0; i<NROWS;i++){
      int row = i*NCOLS;
      for(int j = 0; j<NCOLS;j++){
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
    for(int i = 0; i<NROWS;i++){
      int row = i*NCOLS;
      for(int j = 0; j<NCOLS;j++){
        outfile << elems[row+j]<<" ";
        if(j==NCOLS-1){
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
  Cmatrix<T> result(NROWS,B.NCOLS);

  for(int i=0; i<result.NROWS; i++){
    int resrow=i*result.NCOLS;
    int arow=i*NCOLS;
    for(int j=0; j<result.NCOLS; j++){
      for(int k=0; k<NCOLS; k++){
        result.elems[resrow+j] += elems[arow+k]*B.elems[k*B.NCOLS+j];
      }
    }
  }
  return result;

}



#endif
