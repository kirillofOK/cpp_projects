#include "header.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void find_alpha_betha(double *alpha, double *betha, double *y, double *A, double *C, double *B, int n)
{

    alpha[0] = 0;
    betha[0] = 0;

    alpha[1] = B[0] / C[0];
    betha[1] = y[0] / C[0];

    for (int k = 1; k <= n - 1; ++k)
    {

        alpha[k + 1] = B[k] / (C[k] - A[k] * alpha[k]);
        betha[k + 1] = (y[k] + A[k] * betha[k]) / (C[k] - A[k] * alpha[k]);
    }
}

void find_x_hat(double *x_hat, double *alpha, double *betha, double *y, double *A, double *C, int n)
{

    x_hat[n] = (y[n] + A[n] * betha[n]) / (C[n] - A[n] * alpha[n]);

    for (int k = n - 1; k >= 0; k--)
    {

        x_hat[k] = alpha[k + 1] * x_hat[k + 1] + betha[k + 1];
    }
}

double norm(double *x, double *x_hat, int n)
{

    double res = 0;

    for (int i = 0; i < n + 1; ++i)
    {
        res += (x_hat[i] - x[i]) * (x_hat[i] - x[i]);
    }

    res = sqrt(res);

    return res;
}

double residual(double *x_hat, double *y_hat, double *y, double *A, double *C, double *B, int n)
{

    y_hat[0] = C[0] * x_hat[0] - B[0] * x_hat[1];

    for (int i = 1; i < n; ++i)
    {

        y_hat[i] = -A[i] * x_hat[i - 1] + C[i] * x_hat[i] - B[i] * x_hat[i + 1];
    }

    y_hat[n] = -A[n] * x_hat[n - 1] + C[n] * x_hat[n];

    return norm(y, y_hat, n);
}
