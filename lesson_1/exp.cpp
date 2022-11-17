#include "header.hpp"
void expon(){
    double err_1, err_2;
    double h = 1./10;

    printf("\n\n");

    printf("exp(0.5) = %e   сумма ряда (при N = 20) = %lf \n",exp(0.5), taylor_exp(0.5, 20));
    printf("exp(-10) = %e   сумма ряда прямая (при N = 20) = %lf \n",exp(-10), 1/taylor_exp(10, 20));
    printf("Хитрый способ -  exp(0.5) = %e   сумма ряда (при N = 20) = %lf \n\n",exp(0.5), 1/taylor_exp(0.5, 20));

    while (h>1e-15) {
        printf("h = %e\n", h);
        err_1 = (taylor_exp(2+h, 20) - taylor_exp(2,20))/h - taylor_exp(2,20);
        err_2 = (exp(2+h)- exp(2))/h - exp(2);
        printf("Error of derivative in Taylor = %e \n", err_1);
        printf("Error for derivative in formula = %e \n\n", err_2);
        h/=10;
    }
}

double taylor_exp (double x, int N) {
    double sum = 1;
    double X = x;

    for (double i = 0; i < N; i++) {
        sum += X;
        X = X*x/(i+1);
    }

    return sum;

}
