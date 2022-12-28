#include "header.hpp"

int main(int argc, char *argv[])
{
    double start, end;
    int n, k;
    std::string nodes, func;

    std::ofstream output;
    std::ifstream input;

    if (argc != 6)
    {
        std::perror("[incorrect input");
    }

    start = atof(argv[1]);
    end = atof(argv[2]);
    // printf("%f\n", start);

    if (start > end)
    {
        perror("incorrect input");
    }

    n = atoi(argv[3]);
    k = atoi(argv[4]);
    nodes = argv[5];
    func = argv[6];

    output.open("output.txt");
    create_nodes(output, start, end, n, nodes, func);
    output.close();

    input.open("output.txt");
    if (!input.is_open())
    {
        std::perror("Can't read file!");
    }

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout << std::fixed << std::setprecision(10);

    double *X = new double[n];
    double *Y = new double[n];
    double *K = new double[n];

    fill_x_y(input, X, Y, n);

    first_k(X, Y, K, input, n, k);

    input.close();
}
