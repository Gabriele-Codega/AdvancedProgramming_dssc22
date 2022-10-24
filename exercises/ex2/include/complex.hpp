#ifndef COMPLEX_H
#include <iostream>
#include <typeinfo>
#define COMPLEX_H

template <typename T>
class CComplex{
  T re;
  T im;
public:
  //constructor
  CComplex();
  CComplex(const T x,const T y);

  // assign values
  void set_values(const T x,const T y);

  //functions to get real and imaginary parts
  T getre();
  T getim();

  //print the number
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const CComplex<U>& z);
  void print();

  //algebraic operators
  CComplex operator+(const CComplex& b);
  CComplex operator-(const CComplex& b);
  CComplex operator*(const CComplex& b);
  //CComplex operator+(const CComplex& b)
};



//==================================
//=========== Functions ============

template <typename T>
CComplex<T>::CComplex():re(0),im(0){}
template <typename T>
CComplex<T>::CComplex(const T x,const T y):re(x),im(y){}

// assign values
template <typename T>
void CComplex<T>::set_values(const T x,const T y){
  re = x;
  im = y;
}

//functions to get real and imaginary parts
template <typename T>
T CComplex<T>::getre(){
  return re;
}
template <typename T>
T CComplex<T>::getim(){
  return im;
}

//print the number
template <typename T>
std::ostream& operator<<(std::ostream& os, const CComplex<T>& z){
  os<<z.re<<"+("<<z.im<<")i"<<std::endl;
  return os;
}

template <typename T>
void CComplex<T>::print(){
  std::cout<<re<<"+("<<im<<")i"<<std::endl;
}

//algebraic operators
template <typename T>
CComplex<T> CComplex<T>::operator+(const CComplex<T>& b){
  CComplex<T> result;
  if constexpr(std::is_integral_v<T>){
    std::cout<<"Working with integers"<<std::endl;
    result.re = re + b.re;
    result.im = im + b.im;
    return result;
  }
  if constexpr(std::is_same_v<double,T>){
    std::cout<<"Working with doubles"<<std::endl;
    result.re = re + b.re;
    result.im = im + b.im;
    return result;
  } else {
    result.re = re + b.re;
    result.im = im + b.im;
    return result;
  }


}

template <typename T>
CComplex<T> CComplex<T>::operator-(const CComplex<T>& b){
  CComplex<T> result;
  if constexpr(std::is_integral_v<T>){
    std::cout<<"Working with integers"<<std::endl;
    result.re = re - b.re;
    result.im = im - b.im;
    return result;
  }
  if constexpr(std::is_same_v<double,T>){
    std::cout<<"Working with doubles"<<std::endl;
    result.re = re - b.re;
    result.im = im - b.im;
    return result;
  } else {
    result.re = re - b.re;
    result.im = im - b.im;
    return result;
  }
}

template <typename T>
CComplex<T> CComplex<T>::operator*(const CComplex<T>& b){
  CComplex<T> result;
  if constexpr(std::is_integral_v<T>){
    std::cout<<"Working with integers"<<std::endl;
    result.re = re*b.re - im*b.im;
    result.im = im*b.re + re*b.im;
    return result;
  }
  if constexpr(std::is_same_v<double,T>){
    std::cout<<"Working with doubles"<<std::endl;
    result.re = re*b.re - im*b.im;
    result.im = im*b.re + re*b.im;
    return result;
  } else {
    result.re = re*b.re - im*b.im;
    result.im = im*b.re + re*b.im;
    return result;
  }

}

#endif
