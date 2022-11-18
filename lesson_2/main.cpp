#include "header.hpp"

int main(int argc, char* argv[]) {

    double start, end;
    int n;
    std::string nodes, func;

    if (argc != 6) {
        std::perror("[incorrect input");
    }

    start = atof(argv[1]);
    end = atof(argv[2]);
    n = atoi(argv[3]);
    nodes = argv[4];
    func = argv[5];

    

}