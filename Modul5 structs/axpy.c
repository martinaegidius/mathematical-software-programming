#include <stdio.h>
#include <stdlib.h>

// #include "array.h" 
//or just use struct def here
typedef struct array {
    size_t len;
    size_t capacity;
    double *val;
} array_t;


int axpy(const double alpha, const array_t *x,array_t *y){
    if(!(x)||!(y)){
        return 1;
    }
    if(x->len!=y->len||x->len<1||x->capacity!=y->capacity){
        return 1;
    }
    size_t n = x->len;
    //alternative solution with pointers
    // double *xb = x->val;
    // double *yb = y->val;

    for(size_t i=0;i<n;i++){
        y->val[i] += alpha*(x->val[i]);
        //alternative solution with pointers
        //yb[i] += alpha*(xb[i]);
    }
    return 0;
}

int main(){
    double alpha = 2.0,x_arr[4]={1.0,2.2,12.1,18.9},y_arr[4]={1.0,2.0,3.0,4.0};
    size_t n = 4;
    array_t *x = malloc(n*sizeof(double));
    array_t * y = malloc(n*sizeof(double));
    x->val = x_arr;
    x->len = n;
    x->capacity = n;
    y->val = y_arr;
    y->len = n;
    y->capacity = n;
    int outers = axpy(alpha,x,y);
    // printf("return value %d",outers);
    // printf("putput vector: ");
    for(int i=0;i<n;i++){
        printf("%f, ",y->val[i]);
    }
    return 0;
}

