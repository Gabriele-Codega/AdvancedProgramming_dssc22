#include <iostream>

//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
}

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
  }

int main(){
  Shape s;
  Circle c;
}
