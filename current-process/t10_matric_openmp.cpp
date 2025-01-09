#include <iostream>
#include <omp.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>
#include <string>


// init m * n matrix
std::vector<std::vector<int>> initMatrix(int m, int n) {
    std::vector<std::vector<int>> mat(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = (std::rand() % 10);
        }
    }
    return mat;
}


void printMatrix(std::vector<std::vector<int>> mat) {
    for (auto i : mat) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<int>> matrixMultiply(std::vector<std::vector<int>> matA, std::vector<std::vector<int>> matB) {
    int m = matA.size();
    int n = matA[0].size();
    int k = matB[0].size();

    if (n != matB.size()) {
        std::cout << "matA is m * n, matB must is n * k.";
    }

    std::vector<std::vector<int>> mat(m, std::vector<int>(k, 0));

    #pragma omp parallel for collapse(2) shared(A, B, C)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int z = 0; z < n; ++z) {
                mat[i][j] += matA[i][z] + matB[z][j];
            }
        }
    }

    return mat;
}


int main() {
    auto matA = initMatrix(6, 8);
    auto matB = initMatrix(8, 10);

    auto start = std::chrono::high_resolution_clock::now();
    auto res = matrixMultiply(matA, matB);
    auto end = std::chrono::high_resolution_clock::now();

    auto use_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "use time: " << use_time  << std::endl;

    printMatrix(res);

    return 0;
}
