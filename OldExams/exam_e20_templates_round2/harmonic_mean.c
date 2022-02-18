#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double weighted_harmonic_mean(int n, double * x, double * w) {
    if(!x||!w||n<1){return NAN;}
    double nom = 0.0;
    double den = 0.0;
    for(int i=0;i<n;i++){
        if(x[i]<=0||w[i]<=0){return NAN;}
        nom += w[i];
        den += w[i]/x[i];
    }
    printf("nom is %f",nom);
    return nom/den;
}

int main(){
    double x[4] = {1,2,3,4};
    double w[4] = {2,3,1,28};
    double *xp = x;
    double *wp = w;
    int n = 4;

    double output = weighted_harmonic_mean(n,xp,wp);
    printf("\n output %f",output);
    return 0;
}