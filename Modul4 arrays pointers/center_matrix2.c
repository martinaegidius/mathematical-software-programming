#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int dcemv(int n, double *x){
    double mean = 0.0;
    if(n<=0||x==NULL) return 1;
    for (int i=0;i<n;i++) mean+=x[i];
    mean /= n;
    for (int i=0;i<n;i++) x[i] -= mean;
    for (int i=0;i<n;i++){
        printf("\n%f",x[i]);
    }
    return 0;
}

int main(){
    double *x,x_arr[4] = {1,2,3,4};
    int n = 4;
    x = x_arr;
    int out = dcemv(n,x);
    return 0;
}