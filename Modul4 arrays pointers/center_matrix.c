#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int dcemv(int n, double * x){
    //make centering-matrix
    double * C;
    C = malloc(n*n*sizeof(double));
    if(C==NULL||x==NULL||n<1){
        return 1;
    }

    for(int i=0;i<n;i++){
        C[i+n*i] = 1.0;
    }
    
    //calculating our boy
    for(int i=0;i<n*n;i++){
        C[i] -= 1.0/n;
    }
    //using C to calculate the actual output
    double seqsum;
    double * x_holder = malloc(n*sizeof(double));
    if(x_holder==NULL){
        return 1;
    }

    for(int i=0;i<n;i++){
        seqsum = 0.0;
        for(int j=0;j<n;j++){
            seqsum += C[i*n+j]*x[j]; 
        }
        x_holder[i] = seqsum;
        if(isnan(x_holder[i])||isinf(x_holder[i])){
            return 1;
        }
    }
    x = x_holder;
    for(int i=0;i<n;i++){
        printf("\n%f",x[i]);
    }
    free(x_holder);
    free(C);
    return 0;
}



int main(){
    int n = 4, outers;
    double x_val[4] = {1,2,3,4},*x;
    x = x_val;
    outers = dcemv(n,x);
    printf("%d",outers);
    return 0;
}