#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
    size_t m;
    size_t n;
    double **A;
} matrix_t;

int main(){
    matrix_t mat_arr[10];
    (mat_arr+1)->m = 4;
    for(size_t i=0;i<10;i++){
        printf("yes %ld, ",mat_arr[i].m);
    }
    double a_arr[4] = {1,2,3,4};
    double * v = a_arr;
    double b_arr[4] = {12,2,4,6};
    double *x = b_arr;
    unsigned int n = 4;
    //double out = linear_max(x,a,b,n);
    double data[4] = {5.0,-2.0,2.0,0.0};
    data[1] *= 2.0;
    printf("%f",data[1]);
    ++data[1];
    ++data[1];
    printf("%f",data[1]);
    //printf("%f",out);
}