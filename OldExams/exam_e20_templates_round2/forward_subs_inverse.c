#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int darsv(int n, double * a, double * b, double * x) {
    if(n<1||!a||!b||!x){
        return -1;
    }
    else{
        for(int i=0;i<n;i++){
            if(isnan(a[i])||isnan(b[i])||isnan(x[i])||!(a[i])){return -1;}
        }
        for(int i=0;i<n-1;i++){ //forward substitution for lower triangular
            x[i] = x[i]/a[i]; //may overwrite because triangularity
        }
        double seqsum = 0.0;
        for(int j=0;j<n;j++){
            if(j<n-1){
                seqsum += b[j]*x[j];
                printf("\n seqsum %d here %f\n",j,seqsum);
            }
            else{
                x[j] -= seqsum;
                x[j] /= a[j];
            }
        }
        // //subtracting other x'es from last element
        // double seqsum = 0.0;
        // for(int i=0;i<n;i++){ //last element
        //     for(int j=0;j<n;j++){
                
        //     }
        // }
        for(int i=0;i<n;i++){
            printf("%f, ",x[i]);
        }
    }
    return 0;
}

int main(){
    int n = 3;
    double x_arr[3] = {1,2.0,3.0};
    double a_arr[3] = {4,7,20};
    double b_arr[2] = {17,19};
    double * x = x_arr;
    double * a = a_arr;
    double * b = b_arr;
    int out = darsv(n,a,b,x);
    printf("\nExit code %d",out);
    return 0;
}
