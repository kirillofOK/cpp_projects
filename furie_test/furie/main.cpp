#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int func_num, N, M;

    cout << "Введите номер заполнения функции:\n";
    cout << "1. x(1-x)y(1-y)\n2. Дельта функция Дирака\n3. 2*sin(pi * x) * sin(pi * y)\n4. Новая";
    cin >> func_num;

    cout << "Введите частоту x_0, ..., x_M: M = \n";
    cin >> M;

    cout << "Введите частоту y_0, ..., y_N: N = \n";
    cin >> N;

    double *u;
    double *tmp;
    double *C;

    u = new double[(M + 1) * (N + 1)];
    tmp = new double[(N + 1) * (M + 1)];
    C = new double[(M + 1) * (N + 1)];

    input_u(func_num, u, M, N);

    cout << "\nМатрица u:\n";
    matrix_print(u, M + 1, N + 1);

    u2c(u, tmp, C, M, N);

    cout << "\nМатрица C:\n";
    matrix_print(C, M + 1, N + 1);

    c2u(u, tmp, C, M, N);

    cout << "\nМатрица u:\n";
    matrix_print(u, M + 1, N + 1);

    if (func_num == 3)
    {

        cout << "Найдём порядок сходимости для 2*sin(pi*x)*sin(pi*x)\n";

        double *C_true;
        C_true = new double[(M + 1) * (N + 1)];

        // Заполняем массив известных коэффициентов известными значениями
        for (int i = 0; i < M + 1; ++i)
        {
            for (int j = 0; j < N + 1; ++j)
            {
                C_true[i * (M + 1) + j] = 0;
            }
        }
        C_true[1 * (M + 1) + 1] = 1;

        cout << norm(C_true, C, M, N) << '\n';

        delete[] C_true;
    }

    delete[] u;
    delete[] tmp;
    delete[] C;

    return SUCCESS;
}
