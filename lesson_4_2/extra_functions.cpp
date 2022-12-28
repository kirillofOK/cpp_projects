#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

int sgn(double v)
{
    if (abs(v) < 1e-12)
    {
        return 0;
    }
    else if (v > 1e-12)
    {
        return 1;
    }
    else
        return -1;
}

void input_x(double *x, int n)
{

    for (int i = 0; i < n + 1; ++i)
    {

        x[i] = 1;
    }
}

void input_y(double *y, int n)
{

    double h = 1.0 / n;

    cout << "h = " << h << "\n";

    for (int i = 0; i < n + 1; ++i)
    {

        y[i] = 0;
    }

    y[0] = 1 / (h * h);
    y[n] = 1 / (h * h);
}

void input_A_C_B(double *A, double *C, double *B, int n)
{

    double h = 1.0 / n;

    for (int i = 0; i < n + 1; ++i)
    {

        A[i] = 1.0 / (h * h);
        C[i] = 2.0 / (h * h);
        B[i] = 1.0 / (h * h);
    }

    B[n] = 0;
    A[0] = 0;
}
