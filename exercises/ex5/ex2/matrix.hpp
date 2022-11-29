#include <memory>


template<typename T>
class CMatrix{
  std::unique_ptr<T[]> elems;
  int NROWS;
  int NCOLS;

  public:
  CMatrix(const unsigned int N,const unsigned int M);

};


// constructor 
template<typename T>
CMatrix<T>::CMatrix(const unsigned int N, const unsigned int M){
  NROWS = N;
  NCOLS = M;
  elems = std::make_unique<T>(NROWS*NCOLS);

}