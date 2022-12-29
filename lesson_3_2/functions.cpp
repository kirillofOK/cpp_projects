#include "header.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double f_d_d(int f_num, double *x_basis, double *y_basis, int n)
{

    double mult, res = 0;

    // cout << "Считаю " << n << " раздел_разн!" << "\n";

    int i, j;
    for (j = 0; j <= n; ++j)
    {

        mult = 1;

        // cout << "\tj = " << j << "\n";

        // Считаем произведение
        for (i = 0; i <= n; ++i)
        {

            if (i != j)
            {

                // cout << "\tВ условии i = " << i << "\n";

                mult *= x_basis[j] - x_basis[i];

                // cout << "\t\tmult = " << mult << "\n";
            }
        }

        // если подали f(x_basis)
        if (f_num == 0)
        {
            res += y_basis[j] / mult;

            // cout << "\nres = " << res << "\n";
        }

        // если подали phi(x)
        if (f_num == 1)
        {
            res += pow((-1), j) / mult;

            // cout << "\nres = " << res << "\n";
        }
    }

    return res;
}

void find_divided_differences(int f_num, double *func_d, double *x_basis, double *y_basis, int n)
{

    // f_num = 0: f_d -> разделённые разности для y(x0; x1; ... xn+2)
    // f_num = 1: phi_d -> ну понятно, это для phi

    for (int i = 0; i < n + 1; ++i)
    {

        func_d[i] = f_d_d(f_num, x_basis, y_basis, i + 1);
    }
}

double P(double x, double *x_basis, double y_0, double h, double *f_d, double *phi_d, int n)
{

    double sum = 0, w = 1;

    for (int k = 1; k <= n; ++k)
    {

        // cout << "x = " << x << " x_basis[i] = " << x_basis[i] << "\n";
        w *= x - x_basis[k - 1];
        sum += (f_d[k - 1] - h * phi_d[k - 1]) * w;

        // cout << "f_d[i] = " << f_d[i] << " phi_d[i] = " << phi_d[i] << "\n";

        // cout << "w = " << w << "\n";
        // cout << "add = " << (f_d[i] - h*phi_d[i]) << "\n";
        // cout << "sum = " << sum << "\n";
    }

    // cout << "h = " << h <<  " sum = " << sum << "\n";

    return (y_0 - h + sum);
}

void switch_x_basis(int *basis_idx, double *x, double *y, double *x_basis, double *y_basis, double *f_d, double *phi_d, int cur_idx, double cur_delta, double h, int n)
{

    cout << "\ncur_delta = " << cur_delta << "\n";
    cout << "cur_idx = " << cur_idx << "\n";
    cout << "Массив индексов:\n";
    matrix_print(basis_idx, 1, n + 2);

    cout << "Массив x_basis:\n";
    matrix_print(x_basis, 1, n + 2);

    cout << "Массив y_basis:\n";
    matrix_print(y_basis, 1, n + 2);

    // Второй случай
    if (x[cur_idx] < x[basis_idx[0]])
    {

        cout << "\nВторой случай: cur_idx < basis_idx[0]\n";

        int i_0_idx = basis_idx[0];

        double delta_i_null = y[i_0_idx] - P(x[i_0_idx], x_basis, y_basis[0], h, f_d, phi_d, n);
        cout << "delta_i_null = " << delta_i_null << "\n";

        if (sgn(cur_delta) == sgn(delta_i_null))
        {

            cout << "sgn(cur_delta) == sgn(delta_i_null)\n";

            // обновляем точки в базисе
            basis_idx[0] = cur_idx;
            x_basis[0] = x[cur_idx];
            y_basis[0] = y[cur_idx];
        }

        else if (sgn(cur_delta) != sgn(delta_i_null))
        {

            cout << "sgn(cur_delta) != sgn(delta_i_null)\n";

            for (int i = n + 1; i >= 1; --i)
            {

                // Сдвигаем индексы вправо на 1, проворачивая их и ставя на 0ое метсо cur_idx
                basis_idx[i] = basis_idx[i - 1];
                x_basis[i] = x_basis[i - 1];
                y_basis[i] = y_basis[i - 1];
            }

            basis_idx[0] = cur_idx;
            x_basis[0] = x[cur_idx];
            y_basis[0] = y[cur_idx];
        }
    }

    // Третий случай
    else if (x[cur_idx] > x[basis_idx[n + 1]])
    {

        cout << "\nТретий случай: cur_idx > basis_idx[n+1]\n";

        int idx_i_n1 = basis_idx[n + 1];
        cout << "idx_i_n1 = " << idx_i_n1 << "\n";

        double delta_i_n1 = y[idx_i_n1] - P(x[idx_i_n1], x_basis, y_basis[0], h, f_d, phi_d, n);
        cout << "delta_i_n1 = " << delta_i_n1 << "\n";

        if (sgn(cur_delta) == sgn(delta_i_n1))
        {

            cout << "sgn(cur_delta) == sgn(delta_i_n1)\n";

            // обновляем точки в базисе
            basis_idx[n + 1] = cur_idx;
            x_basis[n + 1] = x[cur_idx];
            y_basis[n + 1] = y[cur_idx];
        }

        else if (sgn(cur_delta) != sgn(delta_i_n1))
        {

            cout << "sgn(cur_delta) != sgn(delta_i_n1)\n";

            // обновляем индексы влево и в конец ставим cur_idx
            for (int i = 0; i <= n; ++i)
            {

                basis_idx[i] = basis_idx[i + 1];
                x_basis[i] = x_basis[i + 1];
                y_basis[i] = y_basis[i + 1];
            }

            basis_idx[n + 1] = cur_idx;
            x_basis[n + 1] = x[cur_idx];
            y_basis[n + 1] = y[cur_idx];
        }
    }

    // Первый случай
    else
    {

        cout << "\nПервый случай: cur_idx drinaged into basis_idx\n";

        int idx_v = 0;
        int idx_v1 = 0;
        int i = 0;

        for (int j = 0; j < n + 2; ++j)
        {

            if (basis_idx[j] > cur_idx)
            {

                idx_v = basis_idx[j - 1];
                idx_v1 = basis_idx[j];
                i = j;
                break;
            }
        }

        cout << "idx_v = " << idx_v << " idx_v1 = " << idx_v1 << "\n";

        double delta_v = y[idx_v] - P(x[idx_v], x_basis, y_basis[0], h, f_d, phi_d, n);
        cout << "delta_v = " << delta_v << "\n";

        if (sgn(delta_v) == sgn(cur_delta))
        {

            cout << "sgn(delta_v) == sgn(cur_delta)\n";

            basis_idx[i - 1] = cur_idx;
            x_basis[i - 1] = x[cur_idx];
            y_basis[i - 1] = y[cur_idx];
        }
        else
        {

            double delta_v1 = y[idx_v1] - P(x[idx_v1], x_basis, y_basis[0], h, f_d, phi_d, n);
            cout << "delta_v1 = " << delta_v1 << "\n";

            if (sgn(delta_v1) == sgn(cur_delta))
            {

                cout << "sgn(delta_v1) == sgn(cur_delta)\n";

                basis_idx[i] = cur_idx;
                x_basis[i] = x[cur_idx];
                y_basis[i] = y[cur_idx];
            }

            else
            {
                cout << "\n??? cur_idx drinaged into basis_idx -> ???\n";
            }
        }
    }

    cout << "\nПосле перестановки\n";
    cout << "Массив индексов:\n";
    matrix_print(basis_idx, 1, n + 2);

    cout << "Массив x_basis:\n";
    matrix_print(x_basis, 1, n + 2);

    cout << "Массив y_basis:\n";
    matrix_print(y_basis, 1, n + 2);
}
