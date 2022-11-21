#include "header.hpp"

void create_nodes(std::ofstream &output, double start, double end, int n, std::string nodes, std::string func)
{
    double x_i;
    if ((func == "exp") && (nodes == "uniform"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = start + (end - start) * i / n;
            output << x_i << " " << exp(x_i) << std::endl;
        }
    }
    else if ((func == "exp") && (nodes == "cheb"))
    {
        for (int i = 0; i < n; ++i)
        {
            x_i = (start + end) / 2 + (end - start) * std::cos((2 * i + 1) * M_PI / (2 * n + 2)) / 2;
            output << x_i << " " << exp(x_i) << std::endl;
        }
    }
}
