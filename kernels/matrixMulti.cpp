/**
 * @file matrixMulti.cpp
 * @author Izaak Wolfgang White 
 * @brief kernel to multiply two 3x3 matrices
 * @date 2024-07-29
 * 
 * @note Map DFG does not work with this kernel but it does generate a DFG graph
 */
//! #include <iostream>

#define SIZE 3

void matrixMultiplyKernel(float A[SIZE][SIZE], float B[SIZE][SIZE], float C[SIZE][SIZE]);

float A[SIZE][SIZE] = {
    {1.0, 2.0, 3.0},
    {4.0, 5.0, 6.0},
    {7.0, 8.0, 9.0}
};

float B[SIZE][SIZE] = {
    {9.0, 8.0, 7.0},
    {6.0, 5.0, 4.0},
    {3.0, 2.0, 1.0}
};

float C[SIZE][SIZE] = {0};

int main() {
    matrixMultiplyKernel(A, B, C);
/*
    std::cout << "Matrix C (Result of A * B):" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/
    return 0;
}

void matrixMultiplyKernel(float A[SIZE][SIZE], float B[SIZE][SIZE], float C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            C[i][j] = 0; 
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
