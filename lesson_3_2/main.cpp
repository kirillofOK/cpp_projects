// по человечески перепишем программу. 
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream> 
#include <random>
#include <string>
#include <iterator>
//template <class RandomIt>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
 
double testFunc(double x) //есть проблема с интерполяцией вот тут, понятия не
{    //вот, поменяли значение функции, все заработало как-будто. Попробуем тепер
    //return pow(x, 2); 
    //printf("hjeeeel");// та функция которую мы будем интерполировать 
	//return exp(-fabs(x))*100;
	// cos(x);
	//return 1.0 / (1 + 25 * x * x); // для отутствия сходимости функции рунге   //так вот получили мы такую штуку,
	return abs(x); // четные функции могут интерполировать четную фукнцию, нечетное количество узлов 
} 

// Вводит матрицу разделенных разностей
void vvod(double *X, double* Y, double** fi, int N, double dx, double LEFT){
    for (int i = 0; i < N +1; i++) // и так начнем заполнять наш массив 
    {
        printf("%d\n", i); 
        printf("%lf\n", LEFT + i*dx); 
        fi[i] = new double [N+1];
        X[i] = LEFT + i*dx; 
        Y[i] = testFunc(X[i]);
        fi[i][0] = pow(-1, i);//мы первый столбец матрицы разделенной разности заполняем как-бы значениями функции по идее да.  
    } // i у нас от 0 до N; 

    printf("X[i]                Y[i]                  fi is\n");
    printf("//////////////////////////////////////////////////////////////\n");
    for (int i = 0; i < N+1; i++){
        printf("%lf",X[i]);
        printf("                         %lf,                  %lf\n",Y[i], fi[i][0]);
    } //ввод работает правильно, всего ввели 11 точек при заданнных 10, хорошо
}

void vvod_basis(double *X, double** Y_basis, double* X_basis, int n, int dx_basis){
    for (int i =0; i < n; ++i){
        Y_basis[i] = new double [n];
        X_basis[i] = X[i*dx_basis];
        Y_basis[i][0] = testFunc(X_basis[i]);
    }
        printf("X[i]_basis                Y[i]_basis is\n");
        printf("//////////////////////////////////////////////////////////////\n");
    for (int i = 0; i < n; i++){
        printf("%lf",X_basis[i]);
        printf("                         %lf\n",Y_basis[i][0]      );
    }  
}



void divided_diff_table(double* X_basis, double** Y_basis, double** fi, int n){

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            Y_basis[j][i] = (Y_basis[j][i - 1] - Y_basis[j + 1][i - 1]) / (X_basis[j] - X_basis[i + j]);
            fi[j][i] = (fi[j][i-1] - fi[j+1][i - 1])/ (X_basis[j] - X_basis[i+j]); 
        }
    }
     /*for (int i = 0; i < n; i++) {
        printf("interation number is %d\n", i);
        printf("//////////////////////////////////////////////////\n");
        for (int j = 0; j < n - i; j++) {
            printf("%lf\n", Y_basis[j][i]);
        }
        cout << "\n";
     }


     for (int i = 0; i < n; i++) {
        printf("interation number is %d\n", i);
        printf("//////////////////////////////////////////////////\n");
        for (int j = 0; j < n - i; j++) {
            printf("%lf\n", fi[j][i]);
        }
        cout << "\n";
     }*/

    printf("Last diff difference matrix element is %lf\n", Y_basis[0][n-1]);
    printf("Last diff difference element for -1 is %lf\n", fi[0][n-1]);

    printf("////////////////////////////////////-///////////////////////////////////////////////////////\n");
}



double multipl(double target, double* X, int k){
    double sum = 1;
    for(int i = 0; i < k; i++){
        sum *= (target - X[i]); 
        //printf("on %d interation of aghorim ", i); 
       //printf("sum is %lf\n", sum);
    }
//далее нужно расчитать ошибку значит 

    return sum;
}

double  algo(double* X_basis,double** Y_basis, double** fi, int n, double X_target){
    double h = 0;
    h = Y_basis[0][n-1]/fi[0][n-1];
    double sum = 0; 
    double target = X_target;
    for (int m = 0; m < n; m++){ // цикл, зачем он нам тут нужен 
    double X_target = X_basis[m]; 
    for(int k = 1; k < n-1; k++ )
        sum += (Y_basis[0][k] - h*fi[0][k]) * multipl(X_target, X_basis, k);
   // printf("Polinomial interpol is %lf\n", Y_basis[0][0] - h + sum);
        if (abs(pow(-1, m)*h + Y_basis[0][0] - h + sum - Y_basis[m][0]) > 1e-10){
            printf("SMTHING IS WRONG");
            return -1;
        }
    //printf("Real function is %lf\n", Y_basis[m][0]); // 
        sum = 0; //так, все норм 
    }
    for(int k = 1; k < n-1; k++ )
        sum += (Y_basis[0][k] - h*fi[0][k]) * multipl(target, X_basis, k);
    return  Y_basis[0][0] - h + sum ; 

}

int sign(double x){
    if (x > 0)
        return 0; 
    else 
        return 1; 
}




int main(){ //написать проги все сам, давай сел и написал и надо дискру 
    int N; 
    int n; 
    const double LEFT = -1.0; 
    const double RIGHT  = 2.0;
    scanf("%d", &N); 
    scanf("%d", &n);
    double* X = new double [N+1]; 
    double** Y_basis = new double* [N+1];
    double* Y = new double [N+1]; 
    double** fi = new double* [N+1];
    double*X_basis = new double[n+2]; 
    //надомравномерно задать сетку 
    const double dx = (RIGHT - LEFT) / (N);
    const int dx_basis = (N+1)/(n+2);
    //double target = 0; 
    printf("dx_basis = %lf\n", dx); //получается нулевой просто финальная разность у меня, при этом алгоритм работает 
    n = n+2;
    vvod(X, Y, fi, N, dx, LEFT); 
    vvod_basis(X, Y_basis, X_basis, n, dx_basis);
    /*Y[0][0] = 12;
    Y[1][0] = 13;
    Y[2][0] = 14;
    Y[3][0] = 16;
    X_basis[0] = 5;
    X_basis[1] = 6;
    X_basis[2] = 9;
    X_basis[3] = 11;*/
    //строим матрицу
    //printf("iter is 0\n");
    divided_diff_table(X_basis,Y_basis,fi,n);
    double result = algo(X_basis, Y_basis, fi, n, X_basis[2]);
    double h = Y_basis[0][n-1]/fi[0][n-1];
    printf("Result is: %.12lf h is %.12lf\n", result, h); // pfgjkybkb
    double error = 0; 
    int error_ind = 0;
    for (int i=0; i<N+1; ++i){
        if (error < abs(Y[i] - algo(X_basis, Y_basis, fi, n, X[i]))){
            error = abs(Y[i] - algo(X_basis, Y_basis, fi, n, X[i]));
            error_ind = i;
        }
    }
    //printf("error is %lf\n", error); 
    //printf("error_ind is %d\n", error_ind);

    //while (abs(h - error) > 1e-8){
        int v = -1; // если не подойдет тут то сначала найдем место в массиве элемента
        for (int i =0; i < n; ++i){
            if(X[error_ind] > X_basis[i])
                v++; 
        }
    //printf("pos equals: %d\n", v);
    //printf("X_v %lf\n", X_basis[v]);
    //printf("X_v+1 %lf\n", X_basis[v+1]);
   // printf("X_error is  %lf\n", X[error_ind] );

    while (abs(abs(h) - error) > 1e-12){
       // printf("abs - h = %lf\n", h);
        if((v > -1) && (v < n -1)){
           // printf("sign = %d\n", sign(Y[error_ind] - algo(X_basis, Y_basis, fi, n, X[error_ind])));
            if(sign(Y[error_ind] - algo(X_basis, Y_basis, fi, n, X[error_ind])) == sign(Y_basis[v][0] - algo(X_basis, Y_basis, fi, n, X_basis[v]))){
                 X_basis[v] = X[error_ind];    
            }
            else{ //
                 X_basis[v+1] = X[error_ind];
            }
        }
        else{
            if (v == -1){
                if (sign(Y[error_ind] - algo(X_basis, Y_basis, fi, n, X[error_ind])) == sign(Y_basis[0][0] - algo(X_basis, Y_basis, fi, n, X_basis[0])))
                {
                    X_basis[0] = X[error_ind]; 
                }
                else{
                    for (int j= n-1; j > 0; --j)
                {
                    X_basis[j] = X_basis[j-1]; //по идее сначала надо 
                }
                    X_basis[0] = X[error_ind];     
                }
            }
            else{
                 if (sign(Y[error_ind] - algo(X_basis, Y_basis, fi, n, X[error_ind])) == sign(Y_basis[n-1][0] - algo(X_basis, Y_basis, fi, n, X_basis[n-1])))
                 {
                    X_basis[n-1] = X[error_ind];
                 }
                 else {
                    for (int j=0; j< n - 1; ++j){
                        X_basis[j] = X_basis[j+1]; 
                    }
                    X_basis[n-1] = X[error_ind];
                 }
            }
        }
        for (int i =0 ; i < n; i++){
            Y_basis[i][0] = testFunc(X_basis[i]);
        }
        printf("X[i]_basis                Y[i]_basis is\n");
        printf("//////////////////////////////////////////////////////////////\n");
    for (int i = 0; i < n; i++){
        printf("%lf",X_basis[i]);
        printf("                         %lf\n",Y_basis[i][0]);
    } 
        divided_diff_table(X_basis,Y_basis,fi,n); 
        h = Y_basis[0][n-1]/fi[0][n-1]; 
        printf("h = %lf\n", Y_basis[0][n-1]/fi[0][n-1]);
        error = 0; 
        error_ind = 0;
        for (int i=0; i<N+1; ++i){
            if (error < abs(Y[i] - algo(X_basis, Y_basis, fi, n, X[i]))){
                error = abs(Y[i] - algo(X_basis, Y_basis, fi, n, X[i]));
                error_ind = i;
        }
    }
    //printf("error is %lf\n", error); 
    //printf("error_ind is %d\n", error_ind);
    //while (abs(h - error) > 1e-8){
         v = -1; // если не подойдет тут то сначала найдем место в массиве элемента
        for (int i =0; i < n; ++i){
            if(X[error_ind] > X_basis[i])
                v++;
        }

        printf("         X[i]         Y[i] = F(X[i])       Abs(P(X[i])-Y[i])\n");
	for (int k = 0; k < N; ++k) {
		printf("%18.12lf   %18.12lf   %18.12lf\n", X[k], Y[k], Y[k] - algo(X_basis, Y_basis, fi, n, X[k]));
	}
    } 
    //мы найдем тот оптимальный базис, на котором все строится. Далее

    std::ofstream origin_f; 
        origin_f.open("nodes.txt");
        int i = 0;
        for (int i = 0; i < N + 1; i++){
            origin_f << X[i] << " " << algo(X_basis, Y_basis, fi, n, X[i]) << " " << Y[i]<< "\n";
        } // ну вот тут показываем интерполяцию нужную нам 


   // }
     // пусть это верно как-бы, ну например надо добиться тоэжества 
    //далее одгрузим алгоритм интерполяции сюда 
    //double y_0 = testFunc(X_basis[0]); 
   // проверка быстрая что все ок 
    /*double error = 0; 
    int error_ind = 0;
    double sum = 0;
    //printf("%lf", -0.000/1); //ну вот это как будто норм
    for (int i = 0; i<N+2; i++){
        double X_target = X[i]; 
        for(int k = 1; k < n-1; k++)
            sum += (Y_basis[0][k] - h*fi[0][k]) * multipl(X_target, X_basis, k);
        if (error < abs(Y_basis[0][0] - h + sum - Y[i])){
            error_ind = i;
            error = abs(Y_basis[0][0] - h + sum - Y[i]);
        }
        sum = 0; //
    }
    printf("best error is %lf", error);*/ //ну мы доходим до конца как бы. Лучшая ошибка вот такая, так и напс
    return 0; // ну вроде ок как-бы
} 