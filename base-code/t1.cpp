
#include <cstdint>
#include <iostream>
#include <stdint.h>


struct Info {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};

struct alignas(4) Info2 {
  char a;
  short int b;
  char c;
};

#pragma pack(push)
#pragma pack(1)
struct Info3 {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};
#pragma pack(pop)


int main () {
  std::cout << "Info size: " << sizeof(Info) << std::endl;
  std::cout << "Info alignas: " << alignof(Info) << std::endl;

  std::cout << "Info2 size: " << sizeof(Info2) << std::endl;
  std::cout << "Info2 alignas: " << alignof(Info2) << std::endl;

  std::cout << "Info3 size: " << sizeof(Info3) << std::endl;
  std::cout << "Info3 alignas: " << alignof(Info3) << std::endl;
  return 0;
}
