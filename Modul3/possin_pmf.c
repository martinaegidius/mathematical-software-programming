#include <stdio.h>
#include <math.h>

double poisson_pmf(unsigned long k, double lambda){
    
    double fact = 1;
    if(lambda>0 && k%1==0 && k>3){
        double lambdak=lambda*lambda;
        for (int i=3;i<=k;i++){ //potens-funktion
            lambdak = lambdak*lambda; 
        }
        for (int i=1;i<=k;i++){
            fact *= i; //factorial-function
        }
        printf("factorial evaluates to %f",fact);
        printf("lambdak evaluates to %f",lambdak);
        return (lambdak/fact)*exp(-lambda);
    }
    else if(lambda>0 && k%1==0 && k>2 && k<=3){
        double lambdak = lambda*lambda;
        for (int i=3;i<=k;i++){
            lambdak = lambdak*lambda;
        }
        for (int i=1;i<=k;i++){
            fact *= i; //factorial-function
        }
        printf("factorial evaluates to %f",fact);
        printf("lambdak evaluates to %f",lambdak);
        return (lambdak/fact)*exp(-lambda);
    }
    else if(lambda>0 && k%1==0 && k==2){
        double lambdak = lambda*lambda;
        k = 2;
        printf("factorial evaluates to %lu",k);
        printf("lambdak evaluates to %f",lambdak);
        return (lambdak/fact)*exp(-lambda);
    }
    else if(lambda>0 && k%1==0 && k==1){
        return (lambda)*exp(-lambda);
    }
    else{
        return nan("");
    }
}
int main(void){

    unsigned long k = 3;
    double lambda = 4;
    double outers = poisson_pmf(k,lambda);
    printf("output is %f",outers);
    return 0;
}