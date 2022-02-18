#include <math.h>
#include <stdio.h>

double feval(double x){
    if (x==0)
        return 1.0;
    else 
        return (exp(x)-1.0)/x;
}

int main(void){
    double x = 400;
    double outers = feval(x);
    printf("%f",outers);
}