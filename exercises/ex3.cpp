#include <iostream>

//printing an array recursively, but backwards
void print_array(int* array,int N ){
  if(N==1){
    std::cout<<array[N-1]<<std::endl;
  } else{
    std::cout<<array[N-1];
    print_array(array,N-1);
  }
}

int main(){
  const int size{10};
  int arr[size];
  int n{size};

  for(int i=0;i<size;i++){
    arr[i] = i;
  }
  for(int i=0;i<size;i++){
    std::cout<<arr[i];
  }
  std::cout<<std::endl;

  print_array(arr,n);
  return 0;
}
