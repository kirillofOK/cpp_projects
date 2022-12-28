#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <sstream>
#define _USE_MATH_DEFINES

void create_nodes(std::ofstream &output, double start, double end, int n, std::string nodes, std::string func);
double runge(double x);
void first_k(double *X, double *Y, double *K, std::ifstream &input, int n, int k);
void fill_x_y(std::ifstream &input, double *X, double *Y, int n);