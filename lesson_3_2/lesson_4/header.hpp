#define ERROR 0
#define SUCCESS 1


//in extra_functions.cpp
int sgn(double v);
void input_u(double* u, int M, int N);
void matrix_print(double* x, int M, int N);


//in functions.cpp
void u2c(double* u, double* tmp, double* C, int M, int N);