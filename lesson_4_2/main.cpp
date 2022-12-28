#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    double *x;
    double *y;

    double *A;
    double *C;
    double *B;

    int n;

    cout << "Введите n:\n";
    cin >> n;

    x = new double[n + 1];
    y = new double[n + 1];

    A = new double[n + 1];
    C = new double[n + 1];
    B = new double[n + 1];

    input_x(x, n);
    input_y(y, n);

    input_A_C_B(A, C, B, n);

    double *x_hat;
    double *alpha;
    double *betha;

    x_hat = new double[n + 1];
    alpha = new double[n + 1];
    betha = new double[n + 1];

    find_alpha_betha(alpha, betha, y, A, C, B, n);

    find_x_hat(x_hat, alpha, betha, y, A, C, n);

    cout << "\nEuclidian norm =" << norm(x, x_hat, n) << "\n";

    double *y_hat;
    y_hat = new double[n + 1];

    cout << "\nResidual = " << residual(x_hat, y_hat, y, A, C, B, n) << "\n";

    return SUCCESS;

    delete[] x;
    delete[] y;
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] x_hat;
    delete[] alpha;
    delete[] betha;
}
