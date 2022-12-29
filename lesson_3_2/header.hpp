#define ERROR 0
#define SUCCES 1

// in extra_functions.cpp
int sgn(double v);
int input_x(double *x, int N, int grid_chose, double a, double b);
void matrix_print(double *M, int m, int n);
void matrix_print(int *M, int m, int n); // для базисных точек
int f(double *x, double *y, int n, int f_type);
void input_x_y_basis(int *basis_idx, double *x_basis, double *y_basis, double *x, double *y, int n, int N);

// in functions.cpp
void find_divided_differences(int f_num, double *func_d, double *x_basis, double *y_basis, int n);
double f_d_d(int f_num, double *x_basis, double *y_basis, int n);
double P(double x, double *x_basis, double y_0, double h, double *f_d, double *phi_d, int n);
void switch_x_basis(int *basis_idx, double *x, double *y, double *x_basis, double *y_basis, double *f_d, double *phi_d, int cur_idx, double cur_delta, double h, int n);
