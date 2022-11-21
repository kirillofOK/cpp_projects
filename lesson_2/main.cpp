#include "header.hpp"

int main(int argc, char *argv[])
{

    double start, end;
    int n;
    std::string nodes, func;
    std::ofstream output;

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
}
