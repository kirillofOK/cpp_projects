#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;


int main() {

    int N, M;

    cout << "Введите частоту x_0, ..., x_M: M = \n";
    cin >> M;

    cout << "Введите частоту y_0, ..., y_N: N = \n";
    cin >> N;


    double* u;
    double* tmp;
    double* C;

    u = new double[(M+1) * (N+1)];
    tmp = new double[(M + 1) * (M + 1)];
    C = new double[(M + 1) * (N + 1)];


    input_u(u, M, N);

    cout << "Матрица u:\n";
    matrix_print(u, M + 1, N + 1);


    u2c(u, tmp, C, M, N);


    return SUCCESS;
}