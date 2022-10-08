#include <iostream>

//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class CMyClass{
    int a;
  public:
    CMyClass(int x):a(x){};
};

int main(){
   CMyClass c(7);
   std::cout<<"this won't work"<<std::endl;
   return 0;
}
