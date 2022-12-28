#include "header.hpp"

// Runge function ...
double runge(double x)
{
    return (1 / (1 + 25 * x * x));
}

// Fill X and Y
void fill_x_y(std::ifstream input, double *x, double *y, int n)
{
    std::string str;
    int i = 0;

    while (getline(input, str))
    {
        double x_i = 0.;
        double y_i = 0.;
        std::istringstream iss(str);
        iss >> x_i >> y_i;
        x[i] = x_i;
        y[i] = y_i;
        ++i;
    }
}

// Choose k in first step
void first_k(double *K, double *X, double *Y, int n, int k)
{
    int step = n / k;
    double *idx = new double[n];
    K[0] = X[0];

    for (int i = 1; i < k; ++i)
    {
        K[i] = X[(i + step) % n];
    }
}