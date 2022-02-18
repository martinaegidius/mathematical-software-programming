#include <math.h>
#include <stdio.h>

double softplus_deriv(double x){
    if (x>=120){
        return 1;
    }
    else{
        return exp(x-log1p(exp(x)));
    }
}

int main(void){
    double x = 1000;
    double out = softplus_deriv(x);
    printf("%.50f",out);
    return 0;
}