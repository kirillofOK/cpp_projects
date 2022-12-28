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

void matrix_print(double *x, int M /* кол-во строк */, int N /* кол-во столбцов */)
{

    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < N; j++)
        {

            printf("%1.3e ", x[i * N + j]);
        }

        cout << "\n";
    }
}

void input_u(int func_num, double *u, int M, int N)
{

    double h_x = 1. / M;
    double h_y = 1. / N;

    double x_i, y_j;

    // Задаёт всюду функцию u
    switch (func_num)
    {

    case 1:
        // Моя красивая функция

        for (int i = 0; i <= M; ++i)
        {

            x_i = i * h_x;
            for (int j = 0; j <= N; ++j)
            {

                y_j = j * h_y;

                u[i * (M + 1) + j] = x_i * (1 - x_i) * y_j * (1 - y_j);
            }
        }
        break;

    case 2:
        // Дельта-функция Дирака

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                u[i * (M + 1) + j] = 0;
            }
        }

        u[M / 2 * (M + 1) + N / 2] = 1;

        break;

    case 3:
        // sin(pi * 1/M ) * sin(pi * 1/N)

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                u[i * (M + 1) + j] = 2 * sin(M_PI * h_x * i) * sin(M_PI * h_y * j);
            }
        }

        break;

    case 4:

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                u[i * (M + 1) + j] = 0;
            }
        }

        u[1 * (M + 1) + 1] = 1;

    default:
        cout << "Неверный номер заполнения функции\n";
        break;
    }
}

double norm(double *C_true, double *C, int M, int N)
{

    double max_elem = 0;

    double C_true_ij, C_ij;

    for (int i = 0; i < M + 1; ++i)
    {
        for (int j = 0; j < N + 1; ++j)
        {

            C_true_ij = C_true[i * (M + 1) + j];
            C_ij = C[i * (M + 1) + j];

            if (abs(C_true_ij - C_ij) > max_elem)
            {

                max_elem = abs(C_true_ij - C_ij);
            }
        }
    }

    return max_elem;
}
