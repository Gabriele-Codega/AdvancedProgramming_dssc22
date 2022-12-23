
#include <iostream>
extern "C" {
    void print(char* str) {
       std::cout<<str<<std::endl;
    }
}
