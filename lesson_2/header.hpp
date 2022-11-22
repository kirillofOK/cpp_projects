#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <sstream>
#define _USE_MATH_DEFINES

void create_nodes(std::ofstream &output, double start, double end, int n, std::string nodes, std::string func);
void create_matrix(std::ifstream &input, double *A, int n);
double runge(double x);
void matrix_outputing(double *A, int n);
void b_creating(std::ifstream &input, double *b);
void b_outputting(double *b, int n);
