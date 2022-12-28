#include "header.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;


int sgn(double v){
    if (abs(v) < 1e-12){
        return 0;
    }
    else if (v > 1e-12){
            return 1;
    }
    else
        return -1;
}


void matrix_print(double* x, int M /* кол-во строк */, int N /* кол-во столбцов */){
    
    for(int i = 0; i< M; i++){
        
        for(int j = 0; j< N; j++){

            printf("%1.3e ", x[i*N + j]);
        }

        cout<<"\n";
    }
}


void input_u(double* u, int M, int N){

    // Задаёт всюду функцию u
    for(int i = 0; i <= M; ++i){

        for(int j = 0; j <= N; ++j){

            u[i * (N + 1) + j] = i + j;
        }
    }

    // Определяем нулём по нижней и верхней границе (то есть левый и правый бок матрицы)
    for(int i = 0; i <= M; ++i){

        u[i * (N + 1) + 0] = 0;
        u[i * (N + 1) + N] = 0;
    }

    // Определяем нулём по левой и правой границе (то есть верх и низ матрицы)
    for(int j = 0; j <= N; ++j){

        u[0 + j] = 0;
        u[M * (N + 1) + j] = 0;
    }
}