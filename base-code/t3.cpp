

#include <iostream>
#include <string.h>


int main (int argc, char *argv[]) {
  const char *str = "name";
  std::cout << sizeof(*str) << std::endl;
  std::cout << strlen(str) << std::endl;

  int a = 10;
  int b = 20;
  int const *p = &a;
  p = &b; // *p = 20 error
  std::cout << p << " b " << *p << std::endl;

  int * const q = &b;
  *q = 100;  // q = &a  error
  std::cout << q << " b " << *q << std::endl;

  return 0;
}
