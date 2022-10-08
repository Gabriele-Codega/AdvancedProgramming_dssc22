#include <iostream>
#include <cmath>

// add class for coefficients
class CCoeffs{
  double a;
  double b;
  double c;

public:
  //constructor
  CCoeffs():a(0),b(0),c(0){}

  // add function to input coefficients
  void ask_for_input(){
    double x,y,z;
    std::cout<<"Enter the coefficients"<<std::endl;
    std::cin>>x>>y>>z;
    a = x;
    b = y;
    c = z;
  }

  //add function to print coefficients
  void print(){
    std::cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<std::endl;
  }

  //get coefficients
  double geta(){
    return a;
  }
  double getb(){
    return b;
  }
  double getc(){
    return c;
  }

};

// add function to solve equation with given coeffs
void solve_quadratic_equation(CCoeffs coeffs){
  double a,b,c;
  a = coeffs.geta();
  b = coeffs.getb();
  c = coeffs.getc();

  if (a == 0){
    std::cout<<"a shall not be zero."<<std::endl;
    exit(1);
  }

  double delta;
  double inv2a = 1/(2*a);

  delta = b * b - 4*a*c;

  if (delta >= 0){
    double root = std::sqrt(delta);
    std::cout<<"x1 = "<< (-b+root)*inv2a<<", x2 = "<<(-b-root)*inv2a<<std::endl;
  } else {
    double root = std::sqrt(-delta);
    std::cout<<"x1 = "<< -b*inv2a<<"+i "<<root*inv2a <<", x2 = " <<-b*inv2a<<"-i "<<root*inv2a<<std::endl;
  }
}

int main(){
  CCoeffs coeffs;
  coeffs.ask_for_input();
  coeffs.print();
  solve_quadratic_equation(coeffs);
  return 0;
}
