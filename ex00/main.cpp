#include <iostream>
#include <iomanip>

int main()
{


  int result = -5000;
  unsigned short c = result;
  std::cout << std::fixed;
  std::cout << std::setprecision(5);
  std::cout << result << std::endl;
  std::cout << c << std::endl;
  std::cout << sizeof(result) << std::endl;
  std::cout << sizeof(c) << std::endl; 
  return 0;
};