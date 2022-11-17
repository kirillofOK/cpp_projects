#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int num;
    double sum;
} Pair;

double macheps(void);
void progression();
Pair for_sum_progress(double q);
Pair back_sum_progress(double q, Pair p);
void expon();
double taylor_exp(double x, int N);
