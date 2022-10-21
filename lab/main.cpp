#include "Matrix.h"
#include <iostream>

int main()
{
  Matrix base;
  Matrix size(4, 4);
  
  base[0][0] = 1;
  base += 1;
  
  Matrix second = base;
  base += second;
  
  base *= 0.5;

  std::cout << base;
  
  std::cout << (base == second) << '\n';
  std::cout << (base != second) << '\n';
  
  Matrix input;
  
  std::cin >> input;
  std::cout << input;
}