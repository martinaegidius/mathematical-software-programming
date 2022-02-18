#include "my_dgemv_v1.h"
#include <stdio.h>


int my_dgemv_v1(
    double alpha,
    double beta,
    const array2d_t *A,
    const array_t *x,
    array_t *y
){
    if(!A||!x||!y||x->len!=A->shape[1]||y->len!=A->shape[0]){return 1;}
    else if(A->order == RowMajor){
        double * arr = (double*)malloc(4*sizeof(double));
        double seqsum;
        for(int i = 0;i<A->shape[0];i++){ 
            seqsum = 0.0;
            for(int j=0;j<A->shape[1];j++){
                seqsum += x->val[j]*A->val[j+A->shape[1]*i];
            }
            y->val[i] = seqsum*alpha+(y->val[i]*beta);
        }    
        return 0;
    }
    else if(A->order == ColMajor){
        double * arr = (double*)malloc(4*sizeof(double));
        double seqsum;
        for(int i = 0;i<A->shape[0];i++){ 
            seqsum = 0.0;
            for(int j=0;j<A->shape[1];j++){
                seqsum += x->val[j]*A->val[i+j*A->shape[0]]; //eneste forskel er hvordan du vælger matrix-element
            }
            y->val[i] = seqsum*alpha+(y->val[i]*beta);
        }    
        return 0;
        
    }
    
    
}


int main(void){
    //allocating + filling matrix
    array2d_t * A = (array2d_t*)malloc(12*sizeof(double));
    double avals[12] = {1,4,1,5,2,5,2,6,3,6,3,1};
    A->val = avals; 
    A->shape[0] = 4;
    A->shape[1] = 3;
    A->order = ColMajor;

    //allocating + filling x and y
    array_t * x = (array_t*)malloc(3*sizeof(double));
    array_t * y = (array_t*)malloc(4*sizeof(double));
    double xval[3] = {1,2,3};
    double yval[4] = {3,4,5,7};
    x->val = xval; 
    y->val = yval; 
    x->len = 3;
    y->len = 4;
    double alpha = 2.0;
    double beta = 13;
    int outers = my_dgemv_v1(alpha,beta,A,x,y);
    printf("%d",outers);


    //printing module vector Y
    for(int i=0;i<y->len;i++){
        printf("%f, ",y->val[i]);
    }
    //printing module matrix A
    for(int i=0;i<A->shape[1];i++){
        printf("\n");
        for(int j=0;j<A->shape[0];j++){
            printf("%f, ",A->val[j+i*A->shape[0]]);
        }
    }

    
    return 0;
        
}

