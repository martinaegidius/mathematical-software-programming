#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int darmv(int n, double * a, double * b, double * x) {
    double *x_holder = (double*)malloc(n*sizeof(double));
    if(x_holder==NULL||n<=0||b==NULL||x==NULL||a==NULL){
        return -1;
    }
    for(int i=0;i<n-1;i++){
        x_holder[i] = x[i]*a[i];
        if(isnan(x_holder[i])||isinf(x_holder[i])){
            return -1;
        }
    }
    
    double seqsum = 0.0;
    for(int i=0;i<=n-1;i++){
        seqsum += b[i]*x[i];
        if(i==n-1){
            seqsum += a[i]*x[i];
            x[i] = seqsum;
        } 
    }
    for(int i=0;i<n-1;i++){
        x[i] = x_holder[i];
    }
    free(x_holder);
    printf("\nfinal vector x:\n");
    for(int i=0;i<n;i++){
        printf("%f\n",x[i]);
    }
    return 0;   
}

int main(){
    double a_val[4] = {1,2.7,16.8,11},*a,b_val[3] = {2400,12,67.6},*b,x_val[4] = {0.01,300,30,17},*x;
    int n = 4;
    a = a_val;
    b = b_val;
    x = x_val;
    int returner = darmv(n,a,b,x);
    return returner;
}
