#include <memory>


template<typename T>
class CMatrix{
  std::unique_ptr<T[]> elems;
  int NROWS;
  int NCOLS;

  public:
  CMatrix(const unsigned int& N,const unsigned int& M);
  

  // read and write from/to file
  void read_from_file(std::string fname);
  void write_to_file(std::string fname);

  // multiplication
  CMatrix<T> operator*(const CMatrix<T>& B);

};


// constructor 
template<typename T>
CMatrix<T>::CMatrix(const unsigned int& N, const unsigned int& M){
  NROWS = N;
  NCOLS = M;
  elems = std::make_unique<T>(NROWS*NCOLS);

}

// read
template<typename T>
void CMatrix<T>::read_from_file( std::string fname){
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

// write
template <typename T>
void CMatrix<T>::write_to_file(std::string fname){
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
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B){
  CMatrix<T> result(NROWS,B.NCOLS);

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