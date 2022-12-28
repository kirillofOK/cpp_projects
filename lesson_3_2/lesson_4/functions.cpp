#include "header.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void u2c(double* u, double* tmp, double* C, int M, int N){

    double s;
    double h_x = 1.0 / M;
    double h_y = 1.0 / N;

    //Воспользуемся вспомогательным массивом tmp
    for(int i = 1; i < M; ++i){
        for(int j = 1; j < N; ++j){

            s = 0;            

            for(int t = 1; t < N; ++t){

                s += sin(M_1_PI * (t * h_y) * j) * u[i*(M + 1) + t];
            }

            tmp[ i* (M + 1) + j] = s * sqrt(2);
        }
    }


    //Умножим коэффициенты на значения в вспомогательном массиве
    for(int i = 1; i < M; ++i){
        for(int j = 1; j < N; +j){
            
            s = 0;

            for (int t = 1; t < ; ++){

                
            }

            C[] = s * sqrt(2);
        }
    }
}