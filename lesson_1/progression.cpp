#include "header.hpp"


void progression() {

    double q_1 = 0.5;
    double q_2 = 1./3.;
    double q_3 = 0.99;
    Pair res_1, res_2, res_3;
    Pair res_1_2, res_2_2, res_3_2;

    res_1 = for_sum_progress(q_1);
    res_2 = for_sum_progress(q_2);
    res_3 = for_sum_progress(q_3);

    double dif_1 = abs(res_1.sum - 1/(1-q_1));
    double dif_2 = abs(res_2.sum - 1/(1-q_2));
    double dif_3 = abs(res_3.sum - 1/(1-q_3));

    printf("Sum of progression (with q=1/2)  =  %lf  and  difference between real sum   =  %e\n", res_1.sum, dif_1);
    printf("Sum of progression (with q=1/3)  =  %lf  and  difference between real sum   =  %e\n", res_2.sum, dif_2);
    printf("Sum of progression (with q=0.99)  =  %lf  and  difference between real sum   =  %e\n\n", res_3.sum, dif_3);

    res_1_2 = back_sum_progress(q_1, res_1);
    res_2_2 = back_sum_progress(q_2, res_2);
    res_3_2 = back_sum_progress(q_3, res_3);

    double dif_1_2 = abs(res_1_2.sum - res_1.sum);
    double dif_2_2 = abs(res_2_2.sum - res_2.sum);
    double dif_3_2 = abs(res_3_2.sum - res_3.sum);

    printf("Sum of back progression (with q=1/2)  =  %lf  and  difference between forward and backward sum   =  %e\n", res_1_2.sum, dif_1_2);
    printf("Sum of back progression (with q=1/3)  =  %lf  and  difference between forward and backward sum   =  %e\n", res_2_2.sum, dif_2_2);
    printf("Sum of back progression (with q=0.99)  =  %lf  and  difference between forward and backward sum   =  %e\n", res_3_2.sum, dif_3_2);

}

Pair for_sum_progress(double q){
    Pair pair; 
    pair.num = 0;
    pair.sum = 1;
    double Q = q;

    while (pair.sum + Q > pair.sum) {
        pair.sum += Q;
        Q *= q;
        pair.num += 1;
    }
    return pair;
}

Pair back_sum_progress(double q, Pair p) {
    Pair result;
    result.sum = 1;
    double Q = pow(q, p.num);

    for (int i = 0; i < p.num; i++) {
        result.sum += Q;
        Q /= q;
    }

    return result;
}
