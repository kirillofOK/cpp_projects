#define ERROR 0
#define SUCCESS 1

// in extra_functions.cpp
int sgn(double v);
void input_u(int func_num, double *u, int M, int N);
void matrix_print(double *x, int M, int N);
double norm(double *C_true, double *C, int M, int N);

// in functions.cpp
void u2c(double *u, double *tmp, double *C, int M, int N);
void c2u(double *u, double *tmp, double *C, int M, int N);
