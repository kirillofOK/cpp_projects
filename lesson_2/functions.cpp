#include "header.hpp"

double runge(double x)
{
    return (1 / (1 + 25 * x * x));
}

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
            A[i * n + j] = x;
            x *= x;
        }
    }
}

void matrix_outputing(double *A, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << A[i * n + j] << "  ";
        }
        std::cout << std::endl;
    }
}
