#include <stdio.h>
#include <math.h>

double poisson_pmf(unsigned long k, double lambda){
    if(lambda<=0 ||isnan(lambda)||(k%1))
        return NAN;
    return exp(k*log(lambda)-(lgamma(k+1.0))-lambda);
}
int main(void){

    unsigned long k = 3;
    double lambda = 4;
    double outers = poisson_pmf(k,lambda);
    printf("output is %f",outers);
    return 0;
}