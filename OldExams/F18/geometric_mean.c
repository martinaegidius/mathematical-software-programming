#include <stdio.h>
#include <math.h>

double geo_mean(unsigned int n, const double *x){
    double val = 1.0;
    for(int i=0;i<n;i++){
        if(x[i]<0||isnan(x[i])){
            return NAN;
        }
        else{
            val *= pow(x[i],(1.0/n));
        }
    }
    return val;
    
}

int main(){
    double x[3] = {1,4,7};
    double * arr = x;
    unsigned int n = 3;
    double outers = geo_mean(n,arr);
    printf("%f",outers);
}