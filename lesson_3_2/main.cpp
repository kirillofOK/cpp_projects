#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int N, n, f_type, grid_chose;
    double a, b;

    cout << "\tЗадаём N+1 точку 0...N: N = \n";
    cin >> N;

    cout << "\tСтепень многочлена P: n = \n";
    cin >> n;

    cout << "\tСетка:\n";
    cout << "1.Равномерная\n2.Чебышёвская\n";
    cin >> grid_chose;

    cout << "\tНомер функции:\n";
    cout << "1.Рунге f(x) = 1 / (1 + 25x^2)\n2.Модуль f(x) = |x|\n3.Квадрат f(x) = x^2\n4.Экспонента f(x) = exp(x)\n";
    cin >> f_type;

    cout << "\tОтрезок [a, b]:\n";
    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    // Задаём точки x согласно сетки:
    double *x = new double[N + 1];
    if (input_x(x, N + 1, grid_chose, a, b) != SUCCES)
    {

        cout << "Ошибка при заполнении массива точек x\n";
        delete[] x;
        return ERROR;
    }

    // задаём y = f(x)
    double *y = new double[N + 1];
    if (f(x, y, N + 1, f_type) != SUCCES)
    {

        cout << "Ошибка при заполнении массива y = f(x)\n";
        delete[] x;
        delete[] y;
        return ERROR;
    }

    // cout << "x\n" ;
    // matrix_print(x, 1, N+1);

    // cout << "y\n";
    // matrix_print(y, 1, N+1);

    // будем хранить массив разделённых разностей: для f -> f_d; для phi -> phi_d
    double *f_d = new double[n + 1];
    double *phi_d = new double[n + 1];

    // изначальные точки в базисе
    double *x_basis = new double[n + 2];
    double *y_basis = new double[n + 2];

    int *basis_idx = new int[n + 2];

    // Выбираем исходый базис
    input_x_y_basis(basis_idx, x_basis, y_basis, x, y, n, N);

    for (int counter = 0; counter < 250; ++counter)
    {

        cout << "\n~~~~~~~~Итерация номер " << counter << "~~~~~~~~\n";

        cout << "\nbasis_idx\n";
        matrix_print(basis_idx, 1, n + 2);

        cout << "x_basis\n";
        matrix_print(x_basis, 1, n + 2);

        cout << "y_basis\n";
        matrix_print(y_basis, 1, n + 2);

        find_divided_differences(0, f_d, x_basis, y_basis, n);   // -> разделённая разность для y, т е f(x_0; x_1; ... x_{x+1})
        find_divided_differences(1, phi_d, x_basis, y_basis, n); // -> разделённая разность для phi(x_0; x_1; ... x_{x+1})

        cout << "\nРазделённые разности f_d:\n";
        matrix_print(f_d, 1, n + 1);

        cout << "\nРазделённые разности phi_d:\n";
        matrix_print(phi_d, 1, n + 1);

        // Найдём h
        double h;
        h = f_d[n] / phi_d[n];

        // Найдём h(sigma) - максимально уклонение на узлах базиса
        double h_tmp, h_s = 0;

        for (int i = 0; i <= n + 1; ++i)
        {

            double p_ = P(x_basis[i],
                          x_basis,
                          y_basis[0],
                          h,
                          f_d,
                          phi_d,
                          n);

            h_tmp = y_basis[i] - p_;

            cout << "\t\th = " << h << "\n";

            cout << "\ty_basis[i] = " << y_basis[i] << "\n";

            cout << "\tP = " << p_ << "\n";

            cout << "\th_tmp = " << h_tmp << "\n";

            if (abs(h_tmp) > h_s)
            {
                h_s = abs(h_tmp);
            }
        }

        // Найдём phi(sigma) - максимально уклонение на всех узлах
        double phi_tmp, cur_delta, phi_s = 0;
        int cur_idx = 0;

        for (int i = 0; i <= N; ++i)
        {
            double p;
            p = P(x[i],
                  x_basis,
                  y_basis[0],
                  h,
                  f_d,
                  phi_d,
                  n);
            phi_tmp = y[i] - p;
            // cout << "P = " << p << "\n";
            // cout << "phi_tmp = " << phi_tmp << "\n";

            if (abs(phi_tmp) > phi_s)
            {
                phi_s = abs(phi_tmp);

                cur_idx = i; // номер узла, на котором достигается максимум phi (т е на всех узлах)
                cur_delta = phi_tmp;
            }
        }

        cout << "\nh = " << h << "\n";
        cout << "h_s = " << h_s << "\n";
        cout << "phi_s = " << phi_s << "\n";
        cout << "Разница abs(h_s - phi_s) = " << abs(h_s - phi_s) << "\n";

        if (abs(h_s - phi_s) <= 1e-5)
        {

            cout << "\n~~~~~~~~Алгоритм завершён!~~~~~~~~\n";

            cout << "\ncounter = " << counter << "\n";

            cout << "\nИтоговые индексы базисных точек:\n";
            matrix_print(basis_idx, 1, n + 2);

            cout << "\nБазисные точки:\n";
            matrix_print(x_basis, 1, n + 2);

            cout << "\nЗначение функции в точках\n";
            matrix_print(y_basis, 1, n + 2);

            std::ofstream origin_f, basis_f;
            origin_f.open("/Users/daniilkorolkov/Desktop/EVM/4/3/origins.txt");
            basis_f.open("/Users/daniilkorolkov/Desktop/EVM/4/3/basis.txt");

            int i;
            for (i = 0; i <= N; i++)
            {
                origin_f << x[i] << " " << y[i] << "\n";
            }

            for (i = 0; i < n + 2; i++)
            {
                basis_f << x_basis[i] << " " << P(x_basis[i], x_basis, y_basis[0], h, f_d, phi_d, n) << "\n";
            }

            delete[] f_d;
            delete[] phi_d;

            delete[] x_basis;
            delete[] y_basis;

            delete[] x;
            delete[] y;

            break;
        }
        else
        {

            cout << "\n-----Меняй!-----\n";

            switch_x_basis(basis_idx, x, y, x_basis, y_basis, f_d, phi_d, cur_idx, cur_delta, h, n);
        }
    }

    return SUCCES;
}
