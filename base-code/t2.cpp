
#include <iostream>


void test(int *p)
{
  int a = 1;
  p = &a;
  std::cout << "p: " << p << "   *p: " << *p <<std::endl;
}

void testREFF(int &q)
{
  int a = 12;
  q = a;
}


int main () {
  int *p = nullptr;
  test(p);
  if (p == nullptr)
    std::cout << "p == nullptr" << std::endl;

  int a = 10;
  testREFF(a);
  std::cout << "a: " << a << std::endl;
  return 0;
}

