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

int input_x(double *x, int N, int grid_chose, double a, double b)
{

    int i;

    switch (grid_chose)
    {
    case 1: // равномерная
        for (int i = 0; i < N; i++)
        {

            x[i] = a + i * (b - a) / (N - 1);
        }
        break;

    case 2: // чебышёвские
        for (int i = 0; i < N; i++)
        {

            x[i] = cos(M_PI * (2 * i + 1) / (2 * N));
        }

        sort(x, x + N);
        break;

    default:
        return ERROR;
    }

    return SUCCES;
}

void matrix_print(double *M, int m /* кол-во строк */, int n /* кол-во столбцов */)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
            printf("%10.3e ", M[i * m + j]);

        cout << "\n";
    }
}

void matrix_print(int *M, int m /* кол-во строк */, int n /* кол-во столбцов */)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
            printf("%d ", M[i * m + j]);

        cout << "\n";
    }
}

int f(double *x, double *y, int N, int f_type)
{

    int i;
    switch (f_type)
    {
    // Рунге
    case 1:
        for (i = 0; i < N; i++)
            y[i] = 1 / (1 + 25 * x[i] * x[i]);
        break;

    // Модуль
    case 2:
        for (i = 0; i < N; i++)
            y[i] = fabs(x[i]);
        break;

    // Квадрат
    case 3:
        for (i = 0; i < N; i++)
            y[i] = x[i] * x[i];
        break;

    // Экспонента
    case 4:
        for (i = 0; i < N; i++)
            y[i] = exp(x[i]);
        break;

    default:
        return ERROR;
    }
    return SUCCES;
}

void input_x_y_basis(int *basis_idx, double *x_basis, double *y_basis, double *x, double *y, int n, int N)
{

    // Выбираем изначальный базис

    // Изначальная инициализация точек "равномерная"
    int i;
    for (i = 0; i < n + 2; ++i)
    {
        int idx = (i) * (N + 1) / (n + 2);

        basis_idx[i] = idx;

        x_basis[i] = x[idx];
        y_basis[i] = y[idx];
    }

    /*
    random_device random_device;
    mt19937 generator(random_device());

    int i = 0;
    double* tmp_arr = new double[n+2];
    while( i!= n+2 ){

        uniform_int_distribution<> distribution(0, N);
        int tmp = distribution(generator);
        bool exists = find(tmp_arr, tmp_arr + n+2, tmp) != tmp_arr + n+2;

        if(!exists){
            tmp_arr[i] = tmp;
            ++i;
        }
    }
    sort(tmp_arr, tmp_arr + n + 2);
    cout << "tmp_arr\n";
    matrix_print(tmp_arr, 1, n+2);

    for(i = 0; i < n+2; ++i){
        int idx = tmp_arr[i];
        x_basis[i] = x[idx];
        y_basis[i] = y[idx];
    }
    */
}
