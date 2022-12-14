#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <sstream>
#define _USE_MATH_DEFINES

void test_func(double *x, double *y, int n, std::string func);
void create_nodes(std::ofstream &output, double start,
                  double end, int n, std::string nodes,
                  std::string func, double *x, double *y);
void create_matrix(std::ifstream &input, double *A, int n);
double runge(double x);
void matrix_outputing(double *A, int n);
void b_creating(std::ifstream &input, double *b);
void b_outputting(double *b, int n);
int gauss(double *A, double *b, int n, double *x);
void x_outputting(double *b, int n);
void create_Pn(std::ofstream &P_n, double *x, int n, std::string func);
void create_Ln(std::ofstream &L_n, int n,
               std::string func, double *x, double *y);
void diff(std::ifstream &input, int n, double *x, double *y);
std::string l_i(double *x, int i, int n);
double lagr(double *x, double *y, double arg, int n);
