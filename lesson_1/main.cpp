#include "header.hpp"

int main(int argc, char **argv) {
    
    if (argc == 1){
        printf("Err: incorrect input");
        return 0;
    }
    
    int n = atoi(argv[1]);

    if (n==1) {
        printf("Machine epsilon =  %e \n ", macheps());
        return 0;
    }

    if (n==2) {
        progression();
        return 0;
    }

    if (n==3) {
        expon();
        return 0;
    }

}

