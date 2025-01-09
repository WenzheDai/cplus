#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>


int main() {
    float *a = (float *)malloc(sizeof(float) * 10);

    time_t t;
    std::srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
        a[i] = (float)rand();
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "======" << std::endl;

    float *b = (float *)malloc(sizeof(float) * 10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(1, 100);
    for (int i = 0; i < 10; ++i) {
        b[i] = distrib(gen);
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << b[i] << " ";
    }
    return 0;
}