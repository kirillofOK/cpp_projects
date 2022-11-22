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
            x *= std::pow(-1, j) * x;
        }
    }
    input.seekg(0);
}

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

void b_outputting(double *b, int n)
{
    std::cout << "b vector:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << b[i] << std::endl;
    }
}
