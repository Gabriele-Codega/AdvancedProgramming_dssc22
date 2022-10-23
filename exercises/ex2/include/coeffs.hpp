#ifndef COEFFS_H
#define COEFFS_H

// add class for coefficients
class CCoeffs{
  double a;
  double b;
  double c;

public:
  //constructor
  CCoeffs();

  //set values
  void set(double a, double b, double c);

  // add function to input coefficients
  void ask_for_input();

  //add function to print coefficients
  void print();

  //get coefficients
  double geta();
  double getb();
  double getc();
};

#endif
