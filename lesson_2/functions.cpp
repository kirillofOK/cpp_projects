#include "header.hpp"

// Runge function ...
double runge(double x)
{
    return (1 / (1 + 25 * x * x));
}

// Create matrix ...
void create_matrix(std::ifstream &input, double *A, int n)
{
    char *str = new char;
    double x;
    for (int i = 0; i < n; ++i)
    {
        input.getline(str, ' ');
        x = atof(str);
        for (int j = 0; j < n; ++j)
        {
            A[i * n + j] = std::pow(x, j);
        }
    }
    input.seekg(0);
}

// Output matrix ...
void matrix_outputing(double *A, int n)
{
    std::cout << "Matrix A:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << A[i * n + j] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << std::endl;
}

// Create b vector ...
void b_creating(std::ifstream &input, double *b)
{
    std::string str;
    int i = 0;
    while (getline(input, str))
    {
        double x_i = 0.;
        double y_i = 0.;
        std::istringstream iss(str);
        iss >> x_i >> y_i;
        b[i] = y_i;
        ++i;
    }
}

// Output b vector ...
void b_outputting(double *b, int n)
{
    std::cout << "b vector:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << b[i] << std::endl;
    }
}

// Gauss choose main element in column ...
int gauss(double *A, double *b, int n, double *x)
{
    double max;
    int k, index;
    const double eps = 0.000000000000001;
    k = 0;
    while (k < n)
    {
        max = A[k * n + k];
        index = k;

        for (int i = k + 1; i < n - 1; ++i)
        {
            if (abs(A[i * n + k]) > max)
            {
                max = abs(A[i * n + k]);
                index = i;
            }
        }

        if (abs(max) < eps)
        {
            std::cout << "Degenerate matrix! on step " << k << std::endl
                      << "max =" << max << std::endl;
            return 0;
        }

        for (int j = 0; j < n; ++j)
        {
            double tmp = A[k * n + j];
            A[k * n + j] = A[index * n + j];
            A[index * n + j] = tmp;
        }

        double tmp = b[k];
        b[k] = b[index];
        b[index] = tmp;

        for (int i = k; i < n; ++i)
        {
            double tmp = A[i * n + k];

            if (abs(tmp) < eps)
            {
                continue;
            }

            for (int j = 0; j < n; ++j)
            {
                A[i * n + j] /= tmp;
            }

            b[i] /= tmp;

            if (i == k)
            {
                continue;
            }

            for (int j = 0; j < n; ++j)
            {
                A[i * n + j] = A[i * n + j] - A[k * n + j];
            }

            b[i] = b[i] - b[k];
        }
        // matrix_outputing(A, n);
        k++;
    }
    for (k = n - 1; k >= 0; --k)
    {
        x[k] = b[k];
        for (int i = 0; i < n; ++i)
        {
            b[i] = b[i] - A[i * n + k] * x[k];
        }
    }
    std::cout << "successfully" << std::endl
              << std::endl;
    return 1;
}

// Outputting cooficients of P_n - solution from Gauss ...
void x_outputting(double *b, int n)
{
    std::cout << "x vector:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << b[i] << std::endl;
    }
}

// Create P_n command file for gnuplot
void create_Pn(std::ofstream &P_n, double *x, int n, std::string func)
{
    P_n << "set yrange[-15:15]" << std::endl;
    P_n << "f1(x) = ";
    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
        {
            P_n << "(" << x[i] << ")"
                << "*x**" << i << "+";
        }
        else
        {
            P_n << "(" << x[i] << ")"
                << "*x**" << i << std::endl;
        }
    }
    if (func != "runge")
    {
        P_n << "f2(x) = " << func << "(x)" << std::endl;
        P_n << "plot "
            << "["
            << "-15"
            << ":"
            << "15"
            << "]"
            << "f1(x), f2(x)";
    }
    else
    {
        P_n << "f2(x) = 1/(25 * x**2 + 1)" << std::endl;
        P_n << "plot "
            << "["
            << "-15"
            << ":"
            << "+15"
            << "]"
            << "f1(x), f2(x)";
    }
}
