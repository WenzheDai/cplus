#include<iostream>


int main() {
    // a, b 内存地址不同
    int a = 10;
    int b = a;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
}