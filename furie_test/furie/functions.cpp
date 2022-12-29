#include "header.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void u2c(double *u, double *tmp, double *C, int M, int N)
{

    double x_i, y_j, s;
    double h_x = 1.0 / M;
    double h_y = 1.0 / N;

    // Заполним вспомогательный массив tmp
    for (int j = 1; j < N; ++j)
    {
        for (int i = 1; i < M; ++i)
        {

            s = 0;

            for (int t = 1; t < N; ++t)
            {

                y_j = (-h_y) / 2 + h_y * t;

                s += sin(M_PI * y_j * j) * u[i * (M + 1) + t];
            }

            tmp[i * (M + 1) + j] = sqrt(2) * s;
        }
    }

    // Воспользуемся вспомогательным массивом tmp
    for (int j = 1; j < N; ++j)
    {
        for (int i = 1; i < M; ++i)
        {

            s = 0;

            for (int t = 1; t < M; ++t)
            {

                x_i = (-h_x / 2) + h_x * t;
                s += tmp[t * (M + 1) + j] * sin(M_PI * x_i * i);
            }

            C[i * (M + 1) + j] = sqrt(2) * s * 1. / (M * N);
        }
    }
}

void c2u(double *u, double *tmp, double *C, int M, int N)
{

    double x_i, y_j, s;
    double h_x = 1.0 / M;
    double h_y = 1.0 / N;

    for (int j = 1; j < N; ++j)
    {
        for (int i = 1; i < M; ++i)
        {

            s = 0;

            for (int t = 1; t < N; ++t)
            {

                y_j = (-h_y / 2) + h_y * t;

                s += sin(M_PI * y_j * j) * C[i * (M + 1) + t];
            }

            tmp[i * (M + 1) + j] = sqrt(2) * s;
        }
    }

    for (int j = 1; j < N; ++j)
    {
        for (int i = 1; i < M; ++i)
        {

            s = 0;

            for (int t = 1; t < M; ++t)
            {

                x_i = (-h_x / 2) + h_x * t;
                s += tmp[t * (M + 1) + j] * sin(M_PI * x_i * i);
            }

            u[i * (M + 1) + j] = sqrt(2) * s;
        }
    }
}
