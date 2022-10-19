#ifndef CLASS_H
#define CLASS_H

// add class for coefficients
class CCoeffs{
  double a;
  double b;
  double c;

public:
  //constructor
  CCoeffs();

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
