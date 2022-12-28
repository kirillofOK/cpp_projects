#define ERROR 0
#define SUCCESS 1

// in extra_functions.cpp
void input_x(double *x, int n);
void input_y(double *y, int n);
void input_A_C_B(double *L, double *D, double *R, int n);

// in functions.cpp
void find_alpha_betha(double *alpha, double *betha, double *y, double *A, double *C, double *B, int n);
void find_x_hat(double *x_hat, double *alpha, double *betha, double *y, double *A, double *C, int n);
double norm(double *x, double *x_hat, int n);
double residual(double *x_hat, double *y_hat, double *y, double *A, double *C, double *B, int n);
