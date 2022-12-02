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
    // printf("%f\n", start);

    if (start > end)
    {
        perror("incorrect input");
    }

    n = atoi(argv[3]);
    nodes = argv[4];
    func = argv[5];

    output.open("output.txt");
    create_nodes(output, start, end, n, nodes, func);
    output.close();

    char *tmp = new char[n];
    double *A = new double[n * n];
    double *b = new double[n];
    double *x = new double[n];

    input.open("output.txt");
    if (!input.is_open())
    {
        std::perror("Can't read file!");
    }

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout << std::fixed << std::setprecision(10);

    create_matrix(input, A, n);
    // matrix_outputing(A, n);
    b_creating(input, b);
    // b_outputting(b, n);
    gauss(A, b, n, x);
    // x_outputting(x, n);

    std::ofstream P_n;
    P_n.open("P_n.txt");
    create_Pn(P_n, x, n, func);
    P_n.close();

    std::ofstream L_n;

    L_n.open("L_n.txt");

    create_Ln(input, L_n, n, func);

    L_n.close();

    input.close();
    delete[] tmp;
    delete[] A;
    delete[] b;
    delete[] x;
}
