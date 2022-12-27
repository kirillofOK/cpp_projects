#include "header.hpp"

int main(int argc, char *argv[])
{

    double start, end;
    int n;

    std::string nodes, func;

    std::ofstream output;
    std::ifstream input;

    if (argc != 6)
    {
        std::perror("[incorrect input");
    }

    start = atof(argv[1]);
    end = atof(argv[2]);

    if (start > end)
    {
        perror("incorrect input");
    }

    n = atoi(argv[3]);
    nodes = argv[4];
    func = argv[5];

    double *x_i = new double[n];
    double *y_i = new double[n];

    double *A = new double[n * n];
    double *b = new double[n];
    double *x = new double[n];

    output.open("output.txt");
    create_nodes(output, start, end, n, nodes, func, x_i, y_i);
    output.close();

    input.open("output.txt");
    if (!input.is_open())
    {
        std::perror("Can't read file!");
    }

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);

    create_matrix(input, A, n);

    b_creating(input, b);

    gauss(A, b, n, x);

    std::ofstream P_n;
    P_n.open("P_n.txt");
    create_Pn(P_n, x, n, func);
    P_n.close();

    std::ofstream L_n;

    L_n.open("L_n.txt");

    create_Ln(L_n, n, func, x_i, y_i);

    L_n.close();

    diff(input, n, x_i, y_i);

    input.close();

    test_func(x_i, y_i, n, func);

    delete[] A;
    delete[] b;
    delete[] x;
    delete[] x_i;
    delete[] y_i;
}
