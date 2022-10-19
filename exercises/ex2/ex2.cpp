#include <iostream>
#include <cmath>

// add class for complex numbers
class CComplex{
  double re;
  double im;
public:
  //constructor
  CComplex():re(0),im(0){}
  CComplex(double x, double y):re(x),im(y){}

  // assign values
  void set_values(double x, double y){
    re = x;
    im = y;
  }

  //functions to get real and imaginary parts
  double getre(){
    return re;
  }
  double getim(){
    return im;
  }

  //print the number
  void print(){
    std::cout<<re<<"+("<<im<<")i"<<std::endl;
  }
};

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

// class for equation
class CQuadratic_Equation{
public:
  CCoeffs coeffs;
  CComplex sols[2];
  // add function to solve equation with given coeffs
  void solve(){
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
      sols[0].set_values((-b+root)*inv2a,0);
      sols[1].set_values((-b-root)*inv2a,0);
    } else {
      double root = std::sqrt(-delta);
      sols[0].set_values(-b*inv2a,root*inv2a);
      sols[1].set_values(-b*inv2a,-root*inv2a);
    }
  }

  //print solutions
  void print_solutions(){
    std::cout<<"x1 = ";
    sols[0].print();

    std::cout<<"x2 = ";
    sols[1].print();
  }
};


int main(){
  CQuadratic_Equation eq;
  eq.coeffs.ask_for_input();
  eq.coeffs.print();
  eq.solve();
  eq.print_solutions();

  return 0;
}
