#ifndef MYSUM_H
#define MYSUM_H

template <typename T>
auto sum(T x){
  return x;
}

template <typename T, typename... Types>
auto sum(T x, Types... args){
  return x+sum(args...);
}

#endif
