#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#define _USE_MATH_DEFINES

void create_nodes(std::ofstream &output, double start, double end, int n, std::string nodes, std::string func);
void create_matrix(double &A, double &b, double &n);
