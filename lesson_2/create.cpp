#include "header.hpp"

void create_nodes(std::ofstream &output, double start,
                  double end, int n, std::string nodes,
                  std::string func, double *x, double *y)
{
    double x_i;
    if ((func == "exp") && (nodes == "uniform"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = start + (end - start) * i / n;
            output << x_i << " " << exp(x_i) << std::endl;
            x[i] = x_i;
            y[i] = exp(x_i);
        }
    }
    else if ((func == "exp") && (nodes == "cheb"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = (start + end) / 2 + (end - start) * std::cos((2 * i + 1) * M_PI / (2 * n + 2)) / 2;
            output << x_i << " " << exp(x_i) << std::endl;
            x[i] = x_i;
            y[i] = exp(x_i);
        }
    }
    else if ((func == "runge") && (nodes == "uniform"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = start + (end - start) * i / n;
            output << x_i << " " << runge(x_i) << std::endl;
            x[i] = x_i;
            y[i] = runge(x_i);
        }
    }
    else if ((func == "runge") && (nodes == "cheb"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = (start + end) / 2 + (end - start) * std::cos((2 * i + 1) * M_PI / (2 * n + 2)) / 2;
            output << x_i << " " << runge(x_i) << std::endl;
            x[i] = x_i;
            y[i] = runge(x_i);
        }
    }
    else if ((func == "abs") && (nodes == "uniform"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = start + (end - start) * i / n;
            output << x_i << " " << abs(x_i) << std::endl;
            x[i] = x_i;
            y[i] = abs(x_i);
        }
    }
    else if ((func == "abs") && (nodes == "cheb"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = (start + end) / 2 + (end - start) * std::cos((2 * i + 1) * M_PI / (2 * n + 2)) / 2;
            output << x_i << " " << abs(x_i) << std::endl;
            x[i] = x_i;
            y[i] = abs(x_i);
        }
    }
    else if ((func == "x_pow_10") && (nodes == "cheb"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = (start + end) / 2 + (end - start) * std::cos((2 * i + 1) * M_PI / (2 * n + 2)) / 2;
            output << x_i << " " << pow(x_i, 10) << std::endl;
            x[i] = x_i;
            y[i] = pow(x_i, 10);
        }
    }
}
